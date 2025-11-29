#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <ostream>
#include <variant>

using namespace std;

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

    // Keywords
    INT,
    RETURN,

    END_OF_FILE
};

class token {
public:
    tokenType type;
    string lexeme;
    Literal literal;
    int line;

    token(tokenType type, string lexeme, Literal literal, int line);

    string toString() const;

private:
};

ostream& operator<<(ostream& os, const token& token);

#endif