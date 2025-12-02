#ifndef PARSER_H
#define PARSER_H

#include "../lexer/token.h"
#include "ast.h"
#include <vector>

class parserType {
    public:
    static int currToken;

        parserType(std::vector<token> tokens);

        ASTType parse_statement();

        static int getNextToken();

        


    private:
        std::vector<token> tokens;
        int current = 0; 
};


#endif