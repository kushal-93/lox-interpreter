#include "../include/Lox.hpp"
#include <iostream>


int main(int argc, char const *argv[]) {
    //ErrorUtil::hadError = false;

    if (argc > 2) {
        std::cout << "Usage: cpplox [script]" << std::endl;
        exit(64);
    }
    else if (argc == 2) {
        cli::Lox::runFile(argv[1]);
    }
    else {
        std::cout << "Lox command prompt: " << std::endl;
        cli::Lox::runPrompt();
    }

    return 0;
}