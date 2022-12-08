#include "writeWAV.h"
#include <iostream>

writeWAV::writeWAV(std::string outpath) {
    input.open(outpath);
    input.close();
    input.open(outpath, std::ios::in | std::ios::binary);
    if (!input.is_open()) {
        std::cout << "wFile don't open!";
    }
}

void writeWAV::writeSecond(sample *buffer) {
    for (int i = 0; i < 44100; ++i) {
        input.write(buffer[i].data, 2);
    }
}

void writeWAV::writeWord(char *word) {
    input.write(word, 4);
}


