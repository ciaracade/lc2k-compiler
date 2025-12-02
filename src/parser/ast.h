#ifndef AST_H
#define AST_H

#include <vector>
#include "../lexer/token.h"

class ASTType {
    public:
        ASTType();
    private:
};

class NumberAST: public ASTType {
    public:
        int value;
        NumberAST(int value);
    private:
};

class VariableAST: public ASTType {
    public:
    std::string name;
    VariableAST(const std::string &Name);
    private:
};

class BinaryOpAST
: public ASTType {
    public:
    char op;
    std:: unique_ptr<ASTType> LHS, RHS;

    BinaryOpAST(char op, std::unique_ptr<ASTType> LHS, std::unique_ptr<ASTType> RHS);
    private:
};


#endif