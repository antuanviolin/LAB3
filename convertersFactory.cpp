
#include "convertersFactory.h"

converters* convertersFactory::createConverters(convertersTypes convertersType) {
    switch (convertersType) {
        case muteType: {
            return new mute;
        }
        case mixType: {
            return new mix;
        }
        case gluingType: {
            return new gluing;
        }
        default:
        {
            throw std::invalid_argument("Error of createConverters");
        }
    }
}
