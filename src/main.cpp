#include "../include/Lox.hpp"
#include <iostream>



int main(int argc, char const *argv[]) {
    std::cout << "hey " << std::endl;
    //ErrorUtil::hadError = false;

    if (argc > 2) {
        std::cout << "Usage: cpplox [script]" << std::endl;
        exit(64);
    }
    else if (argc == 2) {
        cli::Lox::runFile(argv[1]);
    }
    else {
        cli::Lox::runPrompt();
    }

    return 0;
}