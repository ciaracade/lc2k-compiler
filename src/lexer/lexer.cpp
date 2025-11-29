#include "lexer.h"
#include "token.h"
#include "scanner.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

lexerType::lexerType(std::ifstream &fileRead){
    std::string source = "";
    std::string line = "";
    while (getline(fileRead, line)) {
        source += line + "\n";
    }
    scannerType scanner(source);
    this->tokens = scanner.scanTokens();
};


std::ostream& operator<<(std::ostream& os, const lexerType& lt) {
    cout << "Tokens:" << "\n";
    for(size_t i = 0; i < lt.tokens.size(); i++){
        os << "- " << lt.tokens[i] << "\n";
    }
    return os;
};