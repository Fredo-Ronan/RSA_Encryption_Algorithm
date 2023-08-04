#ifndef EUCLIDGCD_H
#define EUCLIDGCD_H

#include <boost/multiprecision/cpp_int.hpp>

cpp_int euclidGCD(cpp_int m, cpp_int n){
    cpp_int temp = 0;

    while(n != 0){
        temp = m % n;
        m = n;
        n = temp;
    }

    return m;
}

#endif