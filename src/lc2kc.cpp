#include "lc2kc.h"
#include "lexer.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void lc2kcType::usage() {
    cout << "Usage: ./lc2kc [filepath]" << "\n";
}

void lc2kcType::runFile(char *path){
    try {
        cout << "Running file..." << path << "\n";
        string line;
        string source;

        ifstream fileRead(path);

        if (!fileRead.is_open()){
            throw "File did not open";
        }

        while (getline(fileRead, line)){
            source += line;
        }

        this->run(&source);

        fileRead.close();
    }
    catch (std::string error){
        cout << "Error running program." << "\n";
        cout << "Message:" << " " << error << "\n";
    }
}

void lc2kcType::run(string *source){
    lexerType lexer(source);

    cout << lexer;
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