#include "converters.h"
#include "readWAV.h"
#include "writeWAV.h"
#include <iostream>

int myCharsToInt(sample sample_) {
    int buffer;
    if (sample_.data[0] & (1 << 8)) {
        sample_.data[0] = sample_.data[0] & 0x7F;
        buffer = (int) sample_.data[1];
        buffer += 256 * (int) sample_.data[0];
        buffer -= 32768;
    } else {
        buffer = (int) sample_.data[1];
        buffer += 256 * (int) sample_.data[0];
    }
    return buffer;
}

void myIntToChars(int data, sample *buffer) {
    if (data > 0) {
        buffer->data[1] = data;
        buffer->data[0] = data >> 8;
    } else {
        data += 32768;
        buffer->data[1] = data;
        buffer->data[0] = data >> 8;
        buffer->data[0] = buffer->data[0] | 0x80;
    }
}

void muteSecond(sample *input1) {
    for (int i = 0; i < 44100; ++i) {
        input1[i].data[0] = 0;
        input1[i].data[1] = 0;
    }
}

void mixSecond(sample *input1, sample *input2) {
    long long middle;
    for (int i = 0; i < 44100; ++i) {
        middle = myCharsToInt(input1[i]);
        middle += myCharsToInt(input2[i]);
        middle /= 2;
        myIntToChars(middle, &input1[i]);
    }
}

void gluingSecond(sample *input1, sample *input2) {
    for (int i = 0; i < 44100; ++i) {
        input1[i].data[0] = input2[i].data[0];
        input1[i].data[1] = input2[i].data[1];
    }
}

void fillAndJump(readWAV *infile, writeWAV *outfile, int seconds) {
    sample second[44100];
    for (int i = 0; i < seconds; ++i) {
        infile->readSecond(second);
        outfile->writeSecond(second);
    }
}

void fillToEnd(readWAV *infile, writeWAV *outfile) {
    while (true) {
        char word[4];
        infile->readWord(word);
        outfile->writeWord(word);
        if (infile->fileEnd()) {
            break;
        }
    }
}

void writeHeader(readWAV *readWav, writeWAV *writeWav) {
    char word[4];
    do {
        readWav->readWord(word);
        writeWav->writeWord(word);
    } while (!((int) word[0] == 100 && (int) word[1] == 97 && (int) word[2] == 116 && (int) word[3] == 97));
    readWav->readWord(word);
    writeWav->writeWord(word);
}

void readHeader(readWAV *readWav) {
    char word[4];
    do {
        readWav->readWord(word);
    } while (!((int) word[0] == 100 && (int) word[1] == 97 && (int) word[2] == 116 && (int) word[3] == 97));
    readWav->readWord(word);
}

void mute::change(std::string infile, std::string outfile, std::string *argument) {
    int seconds[2];
    sample second[44100];
    seconds[0] = std::stoi(argument[0]);
    seconds[1] = std::stoi(argument[1]);
    readWAV readWav(infile);
    writeWAV writeWav(outfile);
    writeHeader(&readWav, &writeWav);
    fillAndJump(&readWav, &writeWav, seconds[0]);
    int secondsChange = seconds[1] - seconds[0];
    while (true) {
        if (secondsChange == 0 || readWav.fileEnd()) {
            break;
        }
        readWav.readSecond(second);
        muteSecond(second);
        writeWav.writeSecond(second);
        --secondsChange;
    }
    fillToEnd(&readWav, &writeWav);
}


void mix::change(std::string infile, std::string outfile, std::string *argument) {
    int secondStart;
    std::string infile2;
    sample second1[44100];
    sample second2[44100];
    std::string numFile = argument[0].substr(1);
    infile2 = "input" + numFile + ".wav";
    secondStart = std::stoi(argument[1]);
    readWAV readWav(infile);
    readWAV readWav2(infile2);
    writeWAV writeWav(outfile);
    writeHeader(&readWav, &writeWav);
    readHeader(&readWav2);
    fillAndJump(&readWav, &writeWav, secondStart);
    while (true) {
        readWav.readSecond(second1);
        readWav2.readSecond(second2);
        mixSecond(second1, second2);
        writeWav.writeSecond(second1);
        if (readWav.fileEnd() || readWav2.fileEnd()) {
            break;
        }
    }
    fillToEnd(&readWav, &writeWav);
}


void gluing::change(std::string infile, std::string outfile, std::string *argument) {
    int secondStart;
    std::string infile2;
    sample second1[44100];
    sample second2[44100];
    std::string numFile = argument[0].substr(1);
    infile2 = "input" + numFile + ".wav";
    secondStart = std::stoi(argument[1]);
    readWAV readWav(infile);
    readWAV readWav2(infile2);
    writeWAV writeWav(outfile);
    writeHeader(&readWav, &writeWav);
    readHeader(&readWav2);
    fillAndJump(&readWav, &writeWav, secondStart);
    while (true) {
        readWav.readSecond(second1);
        readWav2.readSecond(second2);
        gluingSecond(second1, second2);
        writeWav.writeSecond(second1);
        if (readWav.fileEnd() || readWav2.fileEnd()) {
            break;
        }
    }
    fillToEnd(&readWav, &writeWav);
}
