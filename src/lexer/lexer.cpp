#include "lexer.h"
#include "token.h"

#include <string>
#include <iostream>

lexerType::lexerType(ifstream * /* fileStream */){

};


ostream& operator<<(ostream& os, const lexerType& lt) {
    for(size_t i = 0; i < lt.tokens.size(); i++){
        os << lt.tokens[i] << "\n";
    }
    return os;
};