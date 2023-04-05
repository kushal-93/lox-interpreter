#include <iostream>
#include <vector>
#include "Token.h"

class Scanner {

  private:
    std::string source;
    std::vector<Token> tokens;
    int line = 0, start = 0, current = 0;

    bool isAtEnd() {
      return current >= source.length();
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

    void scanToken() {
      char c = advance();
      switch(c) {
        case '(': addToken(LEFT_PAREN); break;
        case ')': addToken(RIGHT_PAREN); break;
        case '{': addToken(LEFT_BRACE); break;
        case '}': addToken(RIGHT_BRACE); break;
        case ',': addToken(COMMA); break;
        case '.': addToken(DOT); break;
        case '-': addToken(MINUS); break;
        case '+': addToken(PLUS); break;
        case ';': addToken(SEMICOLON); break;
        case '*': addToken(STAR); break; 
      }
    }

  public:
    Scanner(std::string source) {
      source = source;
    }

    std::vector<Token> scanTokens() {
      while(!isAtEnd()) {
        start = current;
        scanToken();
      }

      Token eoflToken(EOFL, "", NULL_LITERAL, line);
      tokens.push_back(eoflToken);

      return tokens;
    }


};