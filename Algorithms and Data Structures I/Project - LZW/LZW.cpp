#include "LZW.hpp"

int main(int argc, char const *argv[]) {
    if (argc != 1) {
        std::string passed_action = argv[1];
        if (passed_action == "compress") {
            encode(argv[2]);
            return 1;
        }

        if (passed_action == "decompress") {
            decode(argv[2]);
            return 2;
        }

        if (passed_action == "help") {
            help();
            return 3;
        }
    } else {
        help();
        return 3;
    }

    return 0;
}