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
        void addToken(TokenType type, std::string literal);
        bool match(char expected);
        char peek();
        void scanToken();
        void readString();
        bool isDigit(char c);
        void readNumber(char c);
        void readNumber();

    public:
        Scanner(std::string source);
        std::vector<Token> scanTokens();
        void printSource();
    };
    
}; 


#endif