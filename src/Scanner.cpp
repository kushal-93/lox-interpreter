#include "../include/ErrorUtil.hpp"
#include "../include/Token.hpp"
#include "../include/Scanner.hpp"

#include <iostream>
#include <vector>

namespace cli {

    bool Scanner::isAtEnd() {
        return current >= (int)source.length();
    }

    char Scanner::advance() {
        return source[current++];
    }

    void Scanner::addToken(TokenType type) {
        addToken(type, NULL);
    }

    void Scanner::addToken(TokenType type, Literal* literal) {
        std::string text = source.substr(start, current-start);
        Token token(type, text, literal, line);
        tokens.push_back(token);
    }

    bool Scanner::match(char expected) {
        if(isAtEnd()) 
            return false;
        if(source[current] != expected)
            return false;
        current++;
        return true;
    }

    char Scanner::peek() {
        return source[current];
    }

    void Scanner::scanToken() {
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
        case '/':
            if (match('/')) {
                while (!isAtEnd() && peek()!='\n')
                    current++;
            }
            else 
                addToken(SLASH);
            break;
        case ' ':
            break;
        case '\r':
            break;
        case '\t':
            break;
        case '\n':
            line++;
            break;
        default :
            std::string errorMessage = "Unexpected character: ";
            errorMessage.push_back(c);
            ErrorUtil::error(line, errorMessage);
            break;    
        }
    }

    Scanner::Scanner(std::string src) {
        source = src;
        line = 0;
        start = 0;
        current = 0;
        tokens = {};
    }

    std::vector<Token> Scanner::scanTokens() {
        while (!isAtEnd()) {
            start = current;
            scanToken();
        }

        // Token eoflToken(EOFL, "", NULL, line);
        // // add end of line token at the end of source
        // tokens.push_back(eoflToken);

        return tokens;
    }

    void Scanner::printSource() {
        std::cout << source << std::endl;
    }

};