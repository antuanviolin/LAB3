#include "ReadConfig.h"
#include "ConvertersFactory.h"
#include <map>
#include "SoundProcessor.h"
#include "ReadWAV.h"
#include "WriteWAV.h"

namespace soundProcessor {
    const size_t LENWORD = 4;
    const size_t INFILE = 2;
    const size_t OUTFILE = 1;
    const size_t CONFIGFILE = 0;
    const size_t NUMARG = 2;
    void fileCopy(std::string inpath, std::string outpath) {
        readWAV::ReadWAV readWav(inpath);
        writeWAV::WriteWAV writeWav(outpath);
        while (true) {
            char word[LENWORD];
            readWav.readWord(word);
            writeWav.writeWord(word);
            if (readWav.fileEnd()) {
                break;
            }
        }
    }

    void SoundProcessor(std::string *files) {
        convertersFactory::ConvertersFactory convertersFactory;
        converter::Converters *converter;
        std::map<std::string, convertersFactory::convertersTypes> mapConverters;
        std::string argument[NUMARG];
        mapConverters["mute"] = convertersFactory::muteType;
        mapConverters["mix"] = convertersFactory::mixType;
        mapConverters["gluing"] = convertersFactory::gluingType;
        readConfig::ReadConfig readConfig(files[CONFIGFILE]);
        std::string nowConfig;
        std::string buffer = "buffer.wav";
        fileCopy(files[INFILE], buffer);
        while (true) {
            nowConfig = readConfig.readNewConvert();
            if (nowConfig == "The file has ended") {
                break;
            } else {
                converter = convertersFactory.createConverters(mapConverters[nowConfig]);
                readConfig.readArgumentConvert(argument);
                converter->change(buffer, files[OUTFILE], argument);
                fileCopy(files[OUTFILE], buffer);
            }
        }
    }
}