#include <iostream>
#include <vector>
#include <string>

class ErrorUtil {

public:
    static bool hadError;

    static void report(int line, std::string where, std::string message) {
        std::cout << "[line " << line << "] Error" + where + ": " + message << std::endl;
        hadError = true;
    }

    static void error(int line, std::string message) {
        report(line, "", message);
    }
};