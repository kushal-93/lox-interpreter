#include <iostream>
#include <vector>
#include "Token.cpp"
#include "ErrorUtil.h"

class Scanner {

private:
    std::string source;
    std::vector<Token> tokens;
    int line = 0, start = 0, current = 0;

    bool isAtEnd() {
        return current >= (int)source.length();
    }

    char advance() {
        return source[current++];
    }

    void addToken(TokenType type) {
        addToken(type, NULL_LITERAL);
    }

    void addToken(TokenType type, Literal literal) {
        std::string text = source.substr(start, current);
        Token token(type, text, literal, line);
        tokens.push_back(token);
    }

    bool match(char expected) {
        if(isAtEnd()) 
            return false;
        if(source[current] != expected)
            return false;
        current++;
        return true;
    }

    void scanToken() {
        char c = advance();
        switch (c) {
        case '(':
            addToken(LEFT_PAREN);
            break;
        case ')':
            addToken(RIGHT_PAREN);
            break;
        case '{':
            addToken(LEFT_BRACE);
            break;
        case '}':
            addToken(RIGHT_BRACE);
            break;
        case ',':
            addToken(COMMA);
            break;
        case '.':
            addToken(DOT);
            break;
        case '-':
            addToken(MINUS);
            break;
        case '+':
            addToken(PLUS);
            break;
        case ';':
            addToken(SEMICOLON);
            break;
        case '*':
            addToken(STAR);
            break; // to support multiline command we gotta change this
        case '!':
            addToken(match('=') ? BANG_EQUAL : BANG);
            break;
        case '=':
            addToken(match('=') ? EQUAL_EQUAL : EQUAL);
            break;
        case '>':
            addToken(match('=') ? GREATER_EQUAL : GREATER);
            break;
        case '<':
            addToken(match('=') ? LESS_EQUAL : LESS);
            break;
        default :
            ErrorUtil::error(line, "Unexpected character: "+c); // circular dependency. Should have a error utility class
            break;    
        }


    }

public:
    Scanner(std::string source) {
        source = source;
    }

    std::vector<Token> scanTokens() {
        while (!isAtEnd()) {
            start = current;
            scanToken();
        }

        // Token eoflToken(EOFL, "", NULL_LITERAL, line);
        tokens.push_back(Token(EOFL, "", NULL_LITERAL, line));

        return tokens;
    }
};