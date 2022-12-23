#include "SampleClass.h"

namespace sampleClass {
    const size_t FIRSTBITINDATA = 0;
    const size_t SECONDBITINDATA = 1;
    const size_t ONEWITHASHIFTOFEIGHT = 1 << 8;
    const size_t SHIFT = 8;
    const size_t NEGATIVECONVERTER = 32768;
    const size_t NUMBERBASE = 256;

    void SampleClass::myIntToChars(int i, int convertInt) {
        if (convertInt > 0) {
            second[i].data[SECONDBITINDATA] = convertInt;
            second[i].data[FIRSTBITINDATA] = convertInt >> SHIFT;
        } else {
            convertInt += NEGATIVECONVERTER;
            second[i].data[SECONDBITINDATA] = convertInt;
            second[i].data[FIRSTBITINDATA] = convertInt >> SHIFT;
            second[i].data[FIRSTBITINDATA] = second[i].data[FIRSTBITINDATA] | 0x80;
        }
    }

    int SampleClass::myCharsToInt(int i) {
        int buffer;
        if (second[i].data[FIRSTBITINDATA] & ONEWITHASHIFTOFEIGHT) {
            second->data[FIRSTBITINDATA] = second[i].data[FIRSTBITINDATA] & 0x7F;
            buffer = (int) second[i].data[SECONDBITINDATA];
            buffer += NUMBERBASE * (int) second[i].data[FIRSTBITINDATA];
            buffer -= NEGATIVECONVERTER;
        } else {
            buffer = (int) second[i].data[SECONDBITINDATA];
            buffer += NUMBERBASE * (int) second[i].data[FIRSTBITINDATA];
        }
        return buffer;
    }

    sample *SampleClass::getSecond() {
        return second;
    }
}