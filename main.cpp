#include "soundProcessor.h"

int main(int argc, char **argv) {
    std::string files[argc - 2];
    for (int i = 0; i < argc - 2; ++i) {
        files[i] = argv[i + 2];
    }
    soundProcessor(files);
    return 0;
}
