#ifndef LAB3_CONVERTERSFACTORY_H
#define LAB3_CONVERTERSFACTORY_H

#include "Converters.h"
#include <stdexcept>

namespace convertersFactory {
    enum convertersTypes {
        muteType,
        mixType,
        gluingType
    };

    class ConvertersFactory {
    public:
        converter::Converters *createConverters(convertersTypes convertersType);
    };
}
#endif //LAB3_CONVERTERSFACTORY_H
