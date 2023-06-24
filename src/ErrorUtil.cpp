#include "../include/ErrorUtil.hpp"

#include <iostream>
#include <string>


namespace cli {

    bool ErrorUtil::hadError = false;

    void ErrorUtil::report(int line, std::string where, std::string message) {
        std::cout << "[line " << line << "] Error" + where + ": " + message << std::endl;
        ErrorUtil::hadError = true;
    }

    void ErrorUtil::error(int line, std::string message) {
        report(line, "", message);
    }

};
