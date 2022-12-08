#include "readConfig.h"
#include <iostream>

readConfig::readConfig(std::string &inpath) {
    input.open(inpath);
    if (!input.is_open()) {
        std::cout << "File don't open!";
    }
}

std::string readConfig::readNewConvert() {
    std::string buffer;
    while (input) {
        input >> buffer;
        if (buffer == "#") {
            getline(input, buffer);
        } else if(buffer == "mute" || buffer == "mix" || buffer == "gluing") {
            return buffer;
        }
    }
    return "The file has ended";
}

void readConfig::readArgumentConvert(std::string *buffer) {
    input >> buffer[0];
    input >> buffer[1];
}

readConfig::~readConfig() {
    input.close();
}
