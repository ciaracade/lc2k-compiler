#include "token.h"
#include <sstream>
#include <variant>

using namespace std;

const char* tokenTypeToString(tokenType type) {
    switch(type) {
        case OPEN_BRACE: return "OPEN_BRACE";
        case CLOSE_BRACE: return "CLOSE_BRACE";
        case OPEN_PARENTHESIS: return "OPEN_PARENTHESIS";
        case CLOSE_PARENTHESIS: return "CLOSE_PARENTHESIS";
        case SEMICOLON: return "SEMICOLON";
        case EQUAL: return "EQUAL";
        case PLUS: return "PLUS";
        case IDENTIFIER: return "IDENTIFIER";
        case STRING: return "STRING";
        case NUMBER: return "NUMBER";
        case INT: return "INT";
        case RETURN: return "RETURN";
        case END_OF_FILE: return "END_OF_FILE";
        default: return "UNKNOWN";
    }
}

token::token(tokenType type, string lexeme, Literal literal, int line) {
    this->type = type;
    this->lexeme = lexeme;
    this->literal = literal;
    this->line = line;
};

string token::toString() const {
    ostringstream oss;
    oss << tokenTypeToString(type) << " " << lexeme << " ";

    // Convert variant to string
    std::visit([&oss](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, std::monostate>) {
            oss << "null";
        } else if constexpr (std::is_same_v<T, std::string>) {
            oss << arg;
        } else if constexpr (std::is_same_v<T, double>) {
            oss << arg;
        }
    }, literal);

    return oss.str();
}

ostream& operator<<(ostream& os, const token& token) {
    os << token.toString();
    return os;
};