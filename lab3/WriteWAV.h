#ifndef LAB3_WRITEWAV_H
#define LAB3_WRITEWAV_H

#include <string>
#include <fstream>
#include "ReadWAV.h"
#include "SampleClass.h"

namespace writeWAV {
    class WriteWAV {
    public:
        explicit WriteWAV(std::string outpath);

        void writeSecond(sampleClass::SampleClass *second);

        void writeWord(char *word);

        void writeHeader(readWAV::ReadWAV *readWav);

        void fillAndJump(readWAV::ReadWAV *readWav, int seconds);

        void fillToEnd(readWAV::ReadWAV *readWav);

    private:
        std::ofstream input;
    };
}

#endif //LAB3_WRITEWAV_H
