#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include "token.h"
#include <vector>
#include <unordered_map>

class scannerType {
    public:
        std::string source;
        std::vector<token> tokens;
        static const std::unordered_map<std::string, tokenType> keywords;

        scannerType(std::string source);

        std::vector<token> scanTokens();
        void scanToken();

    private:
        int start = 0;
        int current = 0;
        int line = 1;

        bool isAtEnd();
        char advance();
        char peek();
        bool isDigit(char c);
        bool isAlpha(char c);
        bool isAlphaNumeric(char c);
        void number();
        void identifier();
        void addToken(tokenType type);
        void addToken(tokenType type, Literal literal);
};

#endif
