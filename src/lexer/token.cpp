#include "token.h"
#include <sstream>
#include <variant>

token::token(tokenType type, string lexeme, Literal literal, int line) {
    this->type = type;
    this->lexeme = lexeme;
    this->literal = literal;
    this->line = line;
};

string token::toString() const {
    ostringstream oss;
    oss << to_string(type) << " " << lexeme << " ";

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