#include "readConfig.h"
#include "convertersFactory.h"
#include <map>
#include "soundProcessor.h"
#include "readWAV.h"
#include "writeWAV.h"

void fileCopy(std::string inpath, std::string outpath){
    readWAV readWav(inpath);
    writeWAV writeWav(outpath);
    while (true){
        char word[4];
        readWav.readWord(word);
        writeWav.writeWord(word);
        if (readWav.fileEnd()){
            break;
        }
    }
};

void soundProcessor(std::string *files) {
    convertersFactory convertersFactory;
    converters *converter;
    std::map<std::string, convertersTypes> mapConverters;
    std::string argument[2];
    mapConverters["mute"] = muteType;
    mapConverters["mix"] = mixType;
    mapConverters["gluing"] = gluingType;
    readConfig readConfig(files[0]);
    std::string nowConfig;
    std::string buffer = "buffer.wav";
    fileCopy(files[2], buffer);
    while (true) {
        nowConfig = readConfig.readNewConvert();
        if (nowConfig == "The file has ended") {
            break;
        } else {
            converter = convertersFactory.createConverters(mapConverters[nowConfig]);
            readConfig.readArgumentConvert(argument);
            converter->change(buffer, files[1], argument);
            fileCopy(files[1], buffer);
        }
    }
}
