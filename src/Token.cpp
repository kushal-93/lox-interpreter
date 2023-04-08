#include "../include/Token.hpp"

#include <iostream>
#include <string>

namespace cli {

    Literal getNullLiteral() {
        Literal* l = nullptr; 
        return *l;
    };

    Token::Token(TokenType type, std::string lexeme, Literal literal, int line) {
        type = type;
        lexeme = lexeme;
        literal = literal;
        line = line;
    }

    std::string Token::toString() {
        std::string obj = "";
        if(type == TokenType::NUMBER) {
            obj = std::to_string(literal.num);
        }
        else {
            obj = literal.str;
        }
        return type + " " + lexeme +" "+obj;
    }

};