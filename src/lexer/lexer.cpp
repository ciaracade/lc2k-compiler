#include "lexer.h"
#include "token.h"
#include "scanner.h"

#include <string>
#include <iostream>

lexerType::lexerType(ifstream * fileRead){
    // add scanner here
    scannerType scanner(fileRead);
};


ostream& operator<<(ostream& os, const lexerType& lt) {
    for(size_t i = 0; i < lt.tokens.size(); i++){
        os << lt.tokens[i] << "\n";
    }
    return os;
};