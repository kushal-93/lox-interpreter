#ifndef CLI_SCANNER_HPP
#define CLI_SCANNER_HPP

#include "Token.hpp"
#include "Literal.hpp"

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

namespace cli {
    
    class  Scanner {
    private:
        /* data */
        int line; 
        int start; 
        int current;
        std::string source;
        std::vector<Token> tokens;
        std::unordered_map<std::string, TokenType> keywords = {
            {"and", TokenType::AND}
            ,{"class", TokenType::CLASS}
            ,{"else", TokenType::ELSE}
            ,{"false", TokenType::FALSE}
            ,{"for", TokenType::FOR}
            ,{"fun", TokenType::FUN}
            ,{"if", TokenType::IF}
            ,{"nil", TokenType::NIL}
            ,{"or", TokenType::OR}
            ,{"print", TokenType::PRINT}
            ,{"return", TokenType::RETURN}
            ,{"super", TokenType::SUPER}
            ,{"this", TokenType::THIS}
            ,{"true", TokenType::TRUE}
            ,{"var", TokenType::VAR}
            ,{"while", TokenType::WHILE}
        };

        bool isAtEnd();
        char advance();
        void addToken(TokenType type);
        void addToken(TokenType type, std::shared_ptr<Literal> const& literal);
        bool match(char expected);
        char peek();
        void scanToken();
        void readString();
        bool isDigit(char c);
        void readNumber(bool leadingDecimalPoint);
        bool isAlpha(char c);
        bool isAlphaNumeric(char c);
        void readIdentifier();

    public:
        Scanner(std::string source);
        std::vector<Token> scanTokens();
        void printSource();
    };
    
}; 


#endif