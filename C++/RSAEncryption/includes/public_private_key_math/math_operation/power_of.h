#ifndef POWER_OF_H
#define POWER_OF_H

#include <boost/multiprecision/cpp_int.hpp>

cpp_int power_of(cpp_int number, cpp_int power){
    cpp_int result = 1;
    for(; power>0; power--){
        result *= number;
    }

    return result;
}

#endif