#include "../include/ErrorUtil.hpp"
#include "../include/Token.hpp"
#include "../include/Scanner.hpp"
#include "../include/Literal.hpp"

#include <iostream>
#include <vector>
#include <memory>

namespace cli {

    bool Scanner::isAtEnd() {
        return current >= (int)source.length();
    }

    char Scanner::advance() {
        return source[current++];
    }

    void Scanner::addToken(TokenType type) {
        addToken(type, nullptr);
    }

    void Scanner::addToken(TokenType type, std::shared_ptr<Literal> const& literal) {
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

    void Scanner::readString() {
        while(!isAtEnd() && peek()!='"' && peek()!='\n'){
            current++;
        }
        if(isAtEnd() || peek()=='\n') {
            std::string errorMessage = "End of line or file before string is terminated";
            ErrorUtil::error(line, errorMessage);
            return;
        }
        // current is on closing "
        std::string value = source.substr(start+1, current-start-1);
        // propagate to next character
        current++;
        //Literal literal(value);
        addToken(TokenType::STRING, std::make_shared<Literal>(value));
    }

    bool Scanner::isDigit(char c) {
        return (c >= '0' && c <= '9');
    }

    // void Scanner::readNumber(char c) {
    //     while(isDigit(peek())) {
    //         advance();
    //     }
    //     //value.push_back(c);
    //     std::string value = source.substr(start, current-start);
    //     addToken(NUMBER, value);
    // }

    void Scanner::readNumber(bool leadingDecimalPoint) {
        while(isDigit(peek()))
            advance();

        if(!leadingDecimalPoint && peek() == '.'){
            advance();
            while(isDigit(peek()))
                advance();
        }

        std::string svalue = source.substr(start, current-start);
        double value = std::stod(svalue);
        //Literal literal(value);
        addToken(TokenType::NUMBER, std::make_shared<Literal>(value));
    }

    bool Scanner::isAlpha(char c) {
        return (c == '_' || (c>='a' && c<='z') || (c>='A' && c<='Z'));
    }

    bool Scanner::isAlphaNumeric(char c) {
        return (isAlpha(c) || isDigit(c));
    }

    void Scanner::readIdentifier() {
        while(isAlphaNumeric(peek()))
            advance();
        
        std::string text = source.substr(start, current-start);
        TokenType type = TokenType::IDENTIFIER;
        if (keywords.find(text)!= keywords.end())
            type = keywords[text];
        
        addToken(type);
    }

    void Scanner::scanToken() {
        char c = advance();
        switch (c) {
        case '(':
            addToken(TokenType::LEFT_PAREN);
            break;
        case ')':
            addToken(TokenType::RIGHT_PAREN);
            break;
        case '{':
            addToken(TokenType::LEFT_BRACE);
            break;
        case '}':
            addToken(TokenType::RIGHT_BRACE);
            break;
        case ',':
            addToken(TokenType::COMMA);
            break;
        case '.':
            isDigit(peek()) ? readNumber(true) : addToken(TokenType::DOT); 
            //addToken(DOT);
            break;
        case '-':
            addToken(TokenType::MINUS);
            break;
        case '+':
            addToken(TokenType::PLUS);
            break;
        case ';':
            addToken(TokenType::SEMICOLON);
            break;
        case '*':
            addToken(TokenType::STAR);
            break;
        case '!':
            addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
            break;
        case '=':
            addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
            break;
        case '>':
            addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
            break;
        case '<':
            addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
            break;
        case '/':
            if (match('/')) {
                while (!isAtEnd() && peek()!='\n')
                    current++;
            }
            else 
                addToken(TokenType::SLASH);
            break;
        case '"':
            readString();
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
            if(isDigit(c))
                readNumber(false);
            else if (isAlpha(c)) 
                readIdentifier();
            else {
                std::string errorMessage = "Unexpected character: ";
                errorMessage.push_back(c);
                ErrorUtil::error(line, errorMessage);
            }
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