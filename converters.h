#ifndef LAB3_CONVERTERS_H
#define LAB3_CONVERTERS_H

#include <string>
#include "sample.h"
#include <iostream>

class converters {
public:
    virtual void change(std::string infile, std::string outfile, std::string *argument) = 0;
};

class mute : public converters {
public:
    void change(std::string infile, std::string outfile, std::string *argument);
};

class mix : public converters {
public:
    void change(std::string infile, std::string outfile, std::string *argument);
};

class gluing : public converters {
public:
    void change(std::string infile, std::string outfile, std::string *argument);
};

#endif //LAB3_CONVERTERS_H
