#include "../include/Token.hpp"

#include <iostream>
#include <string>

namespace cli {

    Literal* getNullLiteral() {
        Literal* l = NULL; 
        return l;
    };

    Token::Token(TokenType type, std::string lexeme, Literal* literal, int line) {
        this->type = type;
        this->lexeme = lexeme;
        this->literal = literal;
        this->line = line;
    }

    std::string Token::toString() {
        std::string tokenString;
        std::string obj = "";
        if (!literal) {
            obj = "NIL";
        }
        else {
            if(type == TokenType::NUMBER) {
                obj = std::to_string(literal->num);
            }
            else {
                obj = literal->str;
            }
        }
        tokenString.append(TokenTypeDesc[type]);
        tokenString.append(" ");
        tokenString.append(lexeme);
        tokenString.append(" ");
        tokenString.append(obj);

        //return type + " " + lexeme +" "+obj;
        return tokenString;
    }

};