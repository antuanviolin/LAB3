#include "ReadConfig.h"
#include <iostream>

namespace readConfig {
    const size_t FIRSTARG = 0;
    const size_t SECONDARG = 1;
    ReadConfig::ReadConfig(std::string &inpath) {
        input.open(inpath);
        if (!input.is_open()) {
            std::cout << "File don't open!";
        }
    }

    std::string ReadConfig::readNewConvert() {
        std::string buffer;
        while (input) {
            input >> buffer;
            if (buffer == "#") {
                getline(input, buffer);
            } else if (buffer == "mute" || buffer == "mix" || buffer == "gluing") {
                return buffer;
            }
        }
        return "The file has ended";
    }

    void ReadConfig::readArgumentConvert(std::string *buffer) {
        input >> buffer[FIRSTARG];
        input >> buffer[SECONDARG];
    }

    ReadConfig::~ReadConfig() {
        input.close();
    }
}