#include "lc2kc.h"

#include <iostream>
#include <string>

void lc2kcType::usage() {
    std::cout << "Usage: lc2kc [script]" << "\n";
}

void lc2kcType::runFile(char *argv){
    try {
        std::cout << "Running file..." << "\n";

    }
    catch (std::string error){
        std::cout << "Error reading input file." << "\n";
        std::cout << "Message:" << " " << error << "\n";
    }
}


int main(int argc, char *argv[]) {
    lc2kcType lc2kc;

    if (argc > 1){
        lc2kc.usage();
        return 0;
    } else if (argc == 1){
        lc2kc.runFile(argv[0]);
        return 0;
    } else {
        std::cout << "!TODO: Interactive interpreter" << "\n";
        return 0;
    }
    return 0;
};