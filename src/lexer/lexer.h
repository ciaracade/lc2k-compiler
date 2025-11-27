#include <ostream>
#include <string>
#include <variant>
#include <vector>

using namespace std;
using Literal = std::variant<std::monostate, std::string, double>;


enum tokenType {
OPEN_BRACE, CLOSE_BRACE,
OPEN_PARENTHESIS, CLOSE_PARENTHESIS,

SEMICOLON, 

IDENTIFIER, STRING, INT,

RETURN
};


class token{
    public:
    tokenType type;
    string lexeme;
    Literal literal;
    int line;

    token(tokenType type, string lexeme, Literal literal, int line) {
        this->type = type;
        this->lexeme = lexeme;
        this->literal = literal;
        this->line = line;
    }

    private:
};

ostream& operator<<(ostream& os, const token& token);

class lexerType {
    public:
    vector<token> tokens;

    lexerType(string *source);


    private:
};

ostream& operator<<(ostream& os, const lexerType& lt);