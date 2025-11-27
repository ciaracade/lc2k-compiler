#include "lc2kc.h"

#include <iostream>
#include <string>

using namespace std;

void lc2kcType::usage() {
    cout << "Usage: ./lc2kc [filepath]" << "\n";
}

void lc2kcType::runFile(char *path){
    try {
        cout << "Running file..." << path << "\n";
        this->run(path);

    }
    catch (std::string error){
        cout << "Error reading input file." << "\n";
        cout << "Message:" << " " << error << "\n";
    }
}

void lc2kcType::run(string source){
    // lexer here
}


int main(int argc, char *argv[]) {
    lc2kcType lc2kc;
    // bool verbose = false; I'll add this another time
    cout << argc << "\n";

    if (argc < 1 || argc > 2){
        lc2kc.usage();
        return 0;
    } else if (argc == 2){
        lc2kc.runFile(argv[1]);
        return 0;
    } else {
        std::cout << "!TODO: Interactive interpreter" << "\n";
        return 0;
    }
    return 0;
};