#ifndef CLI_LOX_HPP
#define CLI_LOX_HPP

#include <string>

namespace cli {

    class Lox {
    private:
        /* data */
        
    public:
        static void run(std::string source);
        static void runFile(const char *filePath);
        static void runPrompt();
    };
}

#endif