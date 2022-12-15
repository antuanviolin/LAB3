#ifndef LAB3_CONVERTERS_H
#define LAB3_CONVERTERS_H

#include <string>
#include <iostream>
#include "ReadWAV.h"
#include "WriteWAV.h"
#include "SampleClass.h"

namespace converter {
    class Converters {
    public:
        virtual void change(std::string infile, std::string outfile, std::string *argument) = 0;
    };

    class mute : public Converters {
    public:
        void change(std::string infile, std::string outfile, std::string *argument);
    };

    class mix : public Converters {
    public:
        void change(std::string infile, std::string outfile, std::string *argument);
    };

    class gluing : public Converters {
    public:
        void change(std::string infile, std::string outfile, std::string *argument);
    };
}
#endif //LAB3_CONVERTERS_H
