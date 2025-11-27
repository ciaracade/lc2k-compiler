#include "lexer.h"

#include <string>
#include <iostream>

lexerType::lexerType(string *source){

}

ostream& operator<<(ostream& os, const token& token) {
    os << "Token";
    return os;
}

ostream& operator<<(ostream& os, const lexerType& lt) {
    for(int i = 0; i< lt.tokens.size(); i++){
        os << lt.tokens[i] << "\n";
    }
    return os;
}