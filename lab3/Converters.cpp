#include "Converters.h"

namespace converter {
    const size_t FREQ = 44100;
    const size_t ZERO = 0;
    const size_t FIRSTBITINDATA = 0;
    const size_t SECONDBITINDATA = 1;
    const size_t FIRSTTIME = 0;
    const size_t SECONDTIME = 1;
    const size_t NUMBERFILE = 0;
    const size_t ONE = 1;
    const size_t TWO = 2;
    const size_t STARTSECOND = 1;

    void muteSecond(sampleClass::SampleClass *second) {
        for (int i = 0; i < FREQ; ++i) {
            second->getSecond()[i].data[FIRSTBITINDATA] = ZERO;
            second->getSecond()[i].data[SECONDBITINDATA] = ZERO;
        }
    }

    void mixSecond(sampleClass::SampleClass *second1, sampleClass::SampleClass *second2) {
        long long middle;
        for (int i = 0; i < FREQ; ++i) {
            middle = second1->myCharsToInt(i);
            middle += second2->myCharsToInt(i);
            middle /= TWO;
            second1->myIntToChars(i, middle);
        }
    }

    void gluingSecond(sampleClass::SampleClass *second1, sampleClass::SampleClass *second2) {
        for (int i = 0; i < FREQ; ++i) {
            second1->getSecond()[i].data[FIRSTBITINDATA] = second2->getSecond()[i].data[FIRSTBITINDATA];
            second1->getSecond()[i].data[SECONDBITINDATA] = second2->getSecond()[i].data[SECONDBITINDATA];
        }
    }

    void mute::change(std::string infile, std::string outfile, std::string *argument) {
        int seconds[2];
        sampleClass::SampleClass second{};
        seconds[FIRSTTIME] = std::stoi(argument[FIRSTTIME]);
        seconds[SECONDTIME] = std::stoi(argument[SECONDTIME]);
        readWAV::ReadWAV readWav(infile);
        writeWAV::WriteWAV writeWav(outfile);
        writeWav.writeHeader(&readWav);
        writeWav.fillAndJump(&readWav, seconds[FIRSTTIME]);
        int secondsChange = seconds[SECONDTIME] - seconds[FIRSTTIME];
        while (true) {
            if (secondsChange == ZERO || readWav.fileEnd()) {
                break;
            }
            readWav.readSecond(&second);
            muteSecond(&second);
            writeWav.writeSecond(&second);
            --secondsChange;
        }
        writeWav.fillToEnd(&readWav);
    }


    void mix::change(std::string infile, std::string outfile, std::string *argument) {
        int secondStart;
        std::string infile2;
        sampleClass::SampleClass second1{};
        sampleClass::SampleClass second2{};
        std::string numFile = argument[NUMBERFILE].substr(ONE);
        infile2 = "input" + numFile + ".wav";
        secondStart = std::stoi(argument[STARTSECOND]);
        readWAV::ReadWAV readWav(infile);
        readWAV::ReadWAV readWav2(infile2);
        writeWAV::WriteWAV writeWav(outfile);
        writeWav.writeHeader(&readWav);
        readWav2.readHeader();
        writeWav.fillAndJump(&readWav, secondStart);
        while (true) {
            readWav.readSecond(&second1);
            readWav2.readSecond(&second2);
            mixSecond(&second1, &second2);
            writeWav.writeSecond(&second1);
            if (readWav.fileEnd() || readWav2.fileEnd()) {
                break;
            }
        }
        writeWav.fillToEnd(&readWav);
    }


    void gluing::change(std::string infile, std::string outfile, std::string *argument) {
        int secondStart;
        std::string infile2;
        sampleClass::SampleClass second1{};
        sampleClass::SampleClass second2{};
        std::string numFile = argument[NUMBERFILE].substr(ONE);
        infile2 = "input" + numFile + ".wav";
        secondStart = std::stoi(argument[STARTSECOND]);
        readWAV::ReadWAV readWav(infile);
        readWAV::ReadWAV readWav2(infile2);
        writeWAV::WriteWAV writeWav(outfile);
        writeWav.writeHeader(&readWav);
        readWav2.readHeader();
        writeWav.fillAndJump(&readWav, secondStart);
        while (true) {
            readWav.readSecond(&second1);
            readWav2.readSecond(&second2);
            gluingSecond(&second1, &second2);
            writeWav.writeSecond(&second1);
            if (readWav.fileEnd() || readWav2.fileEnd()) {
                break;
            }
        }
        writeWav.fillToEnd(&readWav);
    }
}