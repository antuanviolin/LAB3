#ifndef LAB3_WRITEWAV_H
#define LAB3_WRITEWAV_H

#include <string>
#include <fstream>
#include "sample.h"

class writeWAV {
public:
    explicit writeWAV(std::string outpath);

    void writeSecond(sample *buffer);

    void writeWord(char *word);

private:
    std::ofstream input;
};


#endif //LAB3_WRITEWAV_H
