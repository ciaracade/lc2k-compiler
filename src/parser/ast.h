#ifndef AST_H
#define AST_H

#include <vector>
#include "../lexer/token.h"

class ASTType {

    public:
        ASTType();

    private:
        std::vector<token> tokens;
        int current = 0;
};

#endif