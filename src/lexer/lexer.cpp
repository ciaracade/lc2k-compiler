#include "lexer.h"
#include "token.h"
#include "scanner.h"

#include <string>
#include <iostream>
#include <fstream>

lexerType::lexerType(ifstream &fileRead){
    string source = "";
    string line = "";
    while (getline(fileRead, line)) {
        source += line + "\n";
    }
    scannerType scanner(source);
    this->tokens = scanner.scanTokens();
};


ostream& operator<<(ostream& os, const lexerType& lt) {
    for(size_t i = 0; i < lt.tokens.size(); i++){
        os << lt.tokens[i] << "\n";
    }
    return os;
};