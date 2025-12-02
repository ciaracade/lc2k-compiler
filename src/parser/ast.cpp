#include <ast.h>

ASTType::ASTType() {};

NumberAST::NumberAST(int value) : value(value) {};

VariableAST::VariableAST(const std::string &name) : name(name) {};

BinaryOpAST::BinaryOpAST(char op, std::unique_ptr<ASTType> LHS, std::unique_ptr<ASTType> RHS) : op(op), LHS(std::move(LHS)), RHS(std::move(RHS)) {};