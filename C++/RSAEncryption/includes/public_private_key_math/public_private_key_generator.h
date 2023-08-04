#ifndef PUBLIC_PRIVATE_KEY_GENERATOR_H
#define PUBLIC_PRIVATE_KEY_GENERATOR_H

#include "./math_operation/euclidGCD.h"

cpp_int find_x_of_n(cpp_int p, cpp_int q){
    return (p - 1) * (q - 1);
}

cpp_int generate_public_key(cpp_int x_of_n){
    for(cpp_int i = 3; i<x_of_n; i++){
        if(euclidGCD(i, x_of_n) == 1){
            return i;
        }
    }

    return -1;
}

cpp_int generate_private_key(cpp_int x_of_n, cpp_int public_key){
    for(cpp_int i = 3; i<=x_of_n;i++){
        if((public_key * i)%x_of_n == 1){
            return i;
        }
    }

    return -1;
}

#endif