#include <ostream>
#include <string>
#include <variant>
#include <vector>
#include "token.h"

using namespace std;

class lexerType {
    public:
    vector<token> tokens;

    lexerType(ifstream *fileStream);


    private:
};

ostream& operator<<(ostream& os, const lexerType& lt);