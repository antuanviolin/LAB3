#ifndef LAB3_CONVERTERSFACTORY_H
#define LAB3_CONVERTERSFACTORY_H

#include "converters.h"
#include "sample.h"
#include <stdexcept>
enum convertersTypes{
    muteType,
    mixType,
    gluingType
};

class convertersFactory {
public:
    converters* createConverters(convertersTypes convertersType);
};

#endif //LAB3_CONVERTERSFACTORY_H
