#ifndef CLI_TOKEN_HPP
#define CLI_TOKEN_HPP

#include <string>

#define NULL_LITERAL getNullLiteral()

namespace cli {

    enum TokenType {
        // Single-character tokens.
        LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
        COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

        // One or two character tokens.
        BANG, BANG_EQUAL,
        EQUAL, EQUAL_EQUAL,
        GREATER, GREATER_EQUAL,
        LESS, LESS_EQUAL,

        // Literals. Also using it to identify Literal active value.
        IDENTIFIER, STRING, NUMBER,

        // Keywords.
        AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
        PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,
  
        EOFL

    };

    union Literal {
        char* str;
        float num;
    };

    Literal* getNullLiteral();

    class Token {
    private:
        TokenType type;
        std::string lexeme;
        Literal* literal;
        int line;
    
    public:
        Token(TokenType type, std::string lexeme, Literal* literal, int line);
        std::string toString();
    };

};



#endif