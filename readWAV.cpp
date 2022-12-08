#include <iostream>
#include "readWAV.h"

readWAV::readWAV(std::string inpath) {
    input.open(inpath, std::ios::in | std::ios::binary);
    if (!input.is_open()) {
        std::cout << "rFile don't open!" << inpath;
    }

}


void readWAV::readSecond(sample *buffer) {
    for (int i = 0; i < 44100; ++i) {
        input.read(buffer[i].data, 2);
    }
}

readWAV::~readWAV() {
    input.close();
}

void readWAV::readWord(char *word) {
    input.read(word, 4);
}

bool readWAV::fileEnd() {
    return input.eof();
}





