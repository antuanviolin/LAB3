#ifndef LAB3_SAMPLECLASS_H
#define LAB3_SAMPLECLASS_H

#include <iostream>

namespace sampleClass {
    const size_t FREQ = 44100;
    const size_t LENSAMPLE = 2;
    struct sample {
        char data[LENSAMPLE];
    };

    class SampleClass {
    public:
        int myCharsToInt(int i);

        void myIntToChars(int i, int converInt);

        sample *getSecond();

    private:
        sample second[FREQ];
    };
}

#endif //LAB3_SAMPLECLASS_H
