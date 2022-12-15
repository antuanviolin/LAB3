#include "ConvertersFactory.h"

namespace convertersFactory {
    converter::Converters *ConvertersFactory::createConverters(convertersTypes convertersType) {
        switch (convertersType) {
            case muteType: {
                return new converter::mute;
            }
            case mixType: {
                return new converter::mix;
            }
            case gluingType: {
                return new converter::gluing;
            }
            default: {
                throw std::invalid_argument("Error of createConverters");
            }
        }
    }
}