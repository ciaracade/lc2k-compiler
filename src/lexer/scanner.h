#include <string>
#include "token.h"
#include <vector>

class scannerType {
    public:
        string source;
        vector<token> tokens;

        scannerType(string source);

        vector<token> scanTokens();
        void scanToken();

    private:
        int start = 0;
        int current = 0;
        int line = 1;

        bool isAtEnd();
        char advance();
        void addToken(tokenType type);
        void addToken(tokenType type, Literal literal);
};

