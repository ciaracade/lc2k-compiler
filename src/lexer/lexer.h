#include <ostream>
#include <string>
#include <variant>
#include <vector>
#include <fstream>
#include "token.h"

class lexerType {
    public:
    std::vector<token> tokens;

    lexerType(std::ifstream &fileStream);


    private:
};

std::ostream& operator<<(std::ostream& os, const lexerType& lt);