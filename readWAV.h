#ifndef LAB3_READWAV_H
#define LAB3_READWAV_H

#include <string>
#include <fstream>
#include <array>
#include "sample.h"

class readWAV {
public:
    explicit readWAV(std::string inpath);

    void readSecond(sample *buffer);

    void readWord(char *word);

    bool fileEnd();

    ~readWAV();
private:
    std::ifstream input;
};


#endif //LAB3_READWAV_H
