#ifndef LAB3_READCONFIG_H
#define LAB3_READCONFIG_H

#include <fstream>
#include <string>
#include "sample.h"

class readConfig {
public:
    explicit readConfig(std::string& inpath);

    std::string readNewConvert();

    void readArgumentConvert(std::string *buffer);

    ~readConfig();

private:
    std::ifstream input;
};


#endif //LAB3_READCONFIG_H
