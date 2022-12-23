#ifndef LAB3_READWAV_H
#define LAB3_READWAV_H

#include <string>
#include <fstream>
#include <array>
#include "SampleClass.h"

namespace readWAV {
    class ReadWAV {
    public:
        explicit ReadWAV(std::string inpath);

        void readSecond(sampleClass::SampleClass *second);

        void readWord(char *word);

        bool fileEnd();

        ~ReadWAV();

        void readHeader();

    private:
        std::ifstream input;
    };
}

#endif //LAB3_READWAV_H
