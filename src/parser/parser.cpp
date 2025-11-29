#include "parser.h"
#include "ast.h"

#include <vector>

parserType::parserType(std::vector<token> tokens){
    this->tokens = tokens;
};

ASTType parserType::parse_statement(){

};