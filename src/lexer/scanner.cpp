#include "scanner.h"

#include <iostream>

using namespace std;

scannerType::scannerType(string source){
    this->source = source;
}

vector<token> scannerType::scanTokens(){
    while(!isAtEnd()){
        start = current;
        scanToken();   // Add token
    }

    tokens.push_back(token(END_OF_FILE, "", Literal{}, line)); // last of file

    return tokens;
}

bool scannerType::isAtEnd(){
    return static_cast<size_t>(current) >= source.length();
}

void scannerType::scanToken(){
    char c = advance();
    switch (c) {
        case '(': addToken(OPEN_PARENTHESIS); break;
        case ')': addToken(CLOSE_PARENTHESIS); break;
        case '{': addToken(OPEN_BRACE); break;
        case '}': addToken(CLOSE_BRACE); break;
        case ';': addToken(SEMICOLON); break;
        default:
            cout << "Error: Unexpected character: " << c; break;
    }
}

char scannerType::advance() {
    return source[current++];
}

void scannerType::addToken(tokenType type) {
    addToken(type, Literal{});
}

void scannerType::addToken(tokenType type, Literal literal) {
    string text = source.substr(start, current - start);
    tokens.push_back(token(type, text, literal, line));
}
