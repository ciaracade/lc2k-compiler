#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <ostream>
#include <variant>

using Literal = std::variant<std::monostate, std::string, double>;

enum tokenType {
    OPEN_BRACE,
    CLOSE_BRACE,
    OPEN_PARENTHESIS,
    CLOSE_PARENTHESIS,

    SEMICOLON,
    EQUAL,
    PLUS,

    IDENTIFIER,
    STRING,
    NUMBER,

    INT,
    RETURN,

    END_OF_FILE
};

const char* tokenTypeToString(tokenType type);

class token {
public:
    tokenType type;
    std::string lexeme;
    Literal literal;
    int line;

    token(tokenType type, std::string lexeme, Literal literal, int line);

    std::string toString() const;

private:
};

std::ostream& operator<<(std::ostream& os, const token& token);

#endif