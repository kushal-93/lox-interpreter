#ifndef CLI_ERROR_UTIL_HPP
#define CLI_ERROR_UTIL_HPP

#include <string>

namespace cli {
    class ErrorUtil {
        private:
            static void report(int line, std::string where, std::string message);
        public: 
            static bool hadError;
            static void error(int line, std::string message);
    };
};


#endif