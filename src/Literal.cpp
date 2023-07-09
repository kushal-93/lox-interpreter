#include "../include/Literal.hpp"
#include <sstream>

namespace cli {
    Literal::Literal(double d) {
        Literal::dblValue = d;
        Literal::lType = 0;
    }

    Literal::Literal(std::string s) {
        Literal::strValue = s;
        Literal::lType = 1;
    }

    double Literal::getDblValue() {
        return dblValue;
    }

    std::string Literal::getStrValue() {
        return strValue;
    }

    std::string Literal::toString() {
        std::string r;
        if(Literal::lType == 0) {
            std::ostringstream strs;
            strs << dblValue;
            r = strs.str();
        }
        else if (Literal::lType == 1)
            r = strValue;
        
        return r;
    }
};
