#ifndef LAB3_READCONFIG_H
#define LAB3_READCONFIG_H

#include <fstream>
#include <string>

namespace readConfig {
    class ReadConfig {
    public:
        explicit ReadConfig(std::string &inpath);

        std::string readNewConvert();

        void readArgumentConvert(std::string *buffer);

        ~ReadConfig();

    private:
        std::ifstream input;
    };
}

#endif //LAB3_READCONFIG_H
