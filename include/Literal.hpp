#ifndef CLI_LITERAL_HPP
#define CLI_LITERAL_HPP

#include <string>

namespace cli {
    class Literal {
    private:
        int lType;
        double dblValue;
        std::string strValue;  
    public:
        Literal(double d);
        Literal(std::string s);
        double getDblValue();
        std::string getStrValue();
        std::string toString();
    };
};


#endif