#include "SoundProcessor.h"

int main(int argc, char **argv) {
    const size_t DEFAULTARG = 2;
    std::string files[argc - DEFAULTARG];
    for (int i = 0; i < argc - DEFAULTARG; ++i) {
        files[i] = argv[i + DEFAULTARG];
    }
    soundProcessor::SoundProcessor(files);
    return 0;
}
