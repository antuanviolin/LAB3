#include "WriteWAV.h"
#include <iostream>

namespace writeWAV {
    const size_t FREQ = 44100;
    const size_t LENSAMPLE = 2;
    const size_t LENWORD = 4;
    const size_t FIRSTARGWORD = 0;
    const size_t SECONDARGWORD = 1;
    const size_t THIRDARGWORD = 2;
    const size_t FOURTHARGWORD = 3;

    WriteWAV::WriteWAV(std::string outpath) {
        input.open(outpath);
        input.close();
        input.open(outpath, std::ios::in | std::ios::binary);
        if (!input.is_open()) {
            std::cout << "wFile don't open!";
        }
    }

    void WriteWAV::writeSecond(sampleClass::SampleClass *second) {
        for (int i = 0; i < FREQ; ++i) {
            input.write(second->getSecond()[i].data, LENSAMPLE);
        }
    }

    void WriteWAV::writeWord(char *word) {
        input.write(word, LENWORD);
    }

    void WriteWAV::writeHeader(readWAV::ReadWAV *readWav) {
        char word[LENWORD];
        do {
            readWav->readWord(word);
            this->writeWord(word);
        } while (!((int) word[FIRSTARGWORD] == 'd' && (int) word[SECONDARGWORD] == 'a' &&
                   (int) word[THIRDARGWORD] == 't' && (int) word[FOURTHARGWORD] == 'a'));
        readWav->readWord(word);
        this->writeWord(word);
    }

    void WriteWAV::fillAndJump(readWAV::ReadWAV *readWav, int seconds) {
        sampleClass::SampleClass second{};
        for (int i = 0; i < seconds; ++i) {
            readWav->readSecond(&second);
            this->writeSecond(&second);
        }
    }

    void WriteWAV::fillToEnd(readWAV::ReadWAV *readWav) {
        while (true) {
            char word[LENWORD];
            readWav->readWord(word);
            this->writeWord(word);
            if (readWav->fileEnd()) {
                break;
            }
        }
    }
}

