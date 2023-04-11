#ifndef CLI_SCANNER_HPP
#define CLI_SCANNER_HPP

#include "Token.hpp"

#include <string>
#include <vector>

namespace cli {
    
    class  Scanner {
    private:
        /* data */
        int line; 
        int start; 
        int current;
        std::string source;
        std::vector<Token> tokens;

        bool isAtEnd();
        char advance();
        void addToken(TokenType type);
        void addToken(TokenType type, Literal* literal);
        bool match(char expected);
        void scanToken();

    public:
        Scanner(std::string source);
        std::vector<Token> scanTokens();
        void printSource();
    };
    
}; 


#endif