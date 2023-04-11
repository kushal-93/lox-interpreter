#include "../include/Lox.hpp"
#include "../include/ErrorUtil.hpp"
#include "../include/Scanner.hpp"
#include "../include/Token.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace cli {

    void Lox::run(std::string source) {
        std::cout << source << std::endl;        
        Scanner scanner(source);
        std::vector<Token> tokens = scanner.scanTokens();

        for(Token token : tokens) {
            std::cout << token.toString() <<", ";
        }
    }

    void Lox::runFile(const char *filePath) {
        std::string path = filePath;
        std::cout << path << std::endl;
        try {
            std::ifstream file(path);
            std::string content = "";
            if(file.is_open()) {
                while(true) {
                    char c = file.get();
                    if(file) {
                        content.push_back(c);
                    }
                    else
                        break;
                }
            }
            Lox::run(content);
            if (ErrorUtil::hadError)
                exit(65);
        }
        catch (std::exception const &) {
            std::cout << "Error" << std::endl;
        }
    }

    void Lox::runPrompt() {
        for(;;) {
            std::cout << "> " ;
            std::string line;
            std::getline(std::cin, line);
            if (line.empty()) 
                break;
            Lox::run(line);
            ErrorUtil::hadError = true;
        }
    }
    
};