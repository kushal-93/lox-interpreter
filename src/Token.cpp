#include <iostream>
#include <fstream>
#include <vector>
#include <string>

enum TokenType {
  // Single-character tokens.
  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
  COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

  // One or two character tokens.
  BANG, BANG_EQUAL,
  EQUAL, EQUAL_EQUAL,
  GREATER, GREATER_EQUAL,
  LESS, LESS_EQUAL,

  // Literals.
  IDENTIFIER, STRING, NUMBER,

  // Keywords.
  AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
  PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE
  
  //EOF

};

class Token {

  const TokenType type;
  const std::string lexeme;
  // java implementation has Object type for literal, we can use string in c++ for now. 
  const std::string literal;
  const int line;

  Token(TokenType type, std::string lexeme, std::string literal, int line) {
    type = type;
    lexeme = lexeme;
    literal = literal;
    line = line;
  }

  public:
    std::string toString() {
      return type + " " + lexeme +" " + literal;
    }

};