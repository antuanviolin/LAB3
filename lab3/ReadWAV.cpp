#include <iostream>
#include "ReadWAV.h"

namespace readWAV {
    const size_t FREQ = 44100;
    const size_t LENWORD = 4;
    const size_t LENSAMPLE = 2;
    const size_t FIRSTARGWORD = 0;
    const size_t SECONDARGWORD = 1;
    const size_t THIRDARGWORD = 2;
    const size_t FOURTHARGWORD = 3;

    ReadWAV::ReadWAV(std::string inpath) {
        input.open(inpath, std::ios::in | std::ios::binary);
        if (!input.is_open()) {
            std::cout << "rFile don't open!" << inpath;
        }

    }

    void ReadWAV::readSecond(sampleClass::SampleClass *second) {
        for (int i = 0; i < FREQ; ++i) {
            input.read(second->getSecond()[i].data, LENSAMPLE);
        }
    }

    ReadWAV::~ReadWAV() {
        input.close();
    }

    void ReadWAV::readWord(char *word) {
        input.read(word, LENWORD);
    }

    bool ReadWAV::fileEnd() {
        return input.eof();
    }

    void ReadWAV::readHeader() {
        char word[LENWORD];
        do {
            this->readWord(word);
        } while (!((int) word[FIRSTARGWORD] == 'd' && (int) word[SECONDARGWORD] == 'a' &&
                   (int) word[THIRDARGWORD] == 't' && (int) word[FOURTHARGWORD] == 'a'));
        this->readWord(word);
    }
}



