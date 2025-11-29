#include "scanner.h"

#include <iostream>

using namespace std;

const std::unordered_map<std::string, tokenType> scannerType::keywords = {
    {"int", INT},
    {"return", RETURN}
};

scannerType::scannerType(string source){
    this->source = source;
}

vector<token> scannerType::scanTokens(){
    while(!isAtEnd()){
        start = current;
        scanToken();   // add token
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
        case '=': addToken(EQUAL); break;
        case '+': addToken(PLUS); break;
        case ' ':
        case '\r':
        case '\t':
            break;
        case '\n':
            line++;
            break;
        default:
            if (isDigit(c)) {
                number();
            } else if (isAlpha(c)) {
                identifier();
            } else {
                cout << "Error: Unexpected character: " << c << "\n";
            }
            break;
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

char scannerType::peek() {
    if (isAtEnd()) return '\0';
    return source[current];
}

bool scannerType::isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool scannerType::isAlpha(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           c == '_';
}

bool scannerType::isAlphaNumeric(char c) {
    return isAlpha(c) || isDigit(c);
}

void scannerType::number() {
    while (isDigit(peek())) advance();

    string text = source.substr(start, current - start);
    double value = std::stod(text);
    addToken(NUMBER, value);
}

void scannerType::identifier() {
    while (isAlphaNumeric(peek())) advance();

    string text = source.substr(start, current - start);

    auto it = keywords.find(text);
    tokenType type = (it != keywords.end()) ? it->second : IDENTIFIER;

    addToken(type);
}
