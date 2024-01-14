#include "../include/Token.hpp"
#include "../include/Literal.hpp"

#include <iostream>
#include <string>
#include <memory>

namespace cli {

    Token::Token(TokenType type, std::string lexeme, std::shared_ptr<Literal> const& literal, int line) {
        this->type = type;
        this->lexeme = lexeme;
        this->literal = literal;
        this->line = line;
    }

    std::string Token::toString() {
        std::string tokenString;
        std::string obj = "";
        if (type == TokenType::NUMBER || type == TokenType::STRING)
            obj = literal->toString();
        else 
            obj = "NIL";
        tokenString.append(TokenTypeDesc[type]);
        tokenString.append(" ");
        tokenString.append(lexeme);
        tokenString.append(" ");
        tokenString.append(obj);
        tokenString.append(" ");
        tokenString.append(std::to_string(line));

        return tokenString;
    }

};