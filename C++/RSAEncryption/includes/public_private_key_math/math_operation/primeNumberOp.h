#ifndef PRIMENUMBEROP_H
#define PRIMENUMBEROP_H

#include <boost/multiprecision/cpp_int.hpp>
#include <cstdlib>
#include <ctime>

bool isPrime(cpp_int number){
    if(number < 2){
        return false;
    }

    for(cpp_int i = 2; i<(number/2) + 1; i++){
        if(number%i==0){
            return false;
        }
    }

    return true;
}

cpp_int generatePrimeNumber(cpp_int min, cpp_int max){
    srand(time(NULL));
    cpp_int generated = (cpp_int) ((cpp_int) rand() % (max - min + 1)) + min;

    while(!isPrime(generated)){
        generated = (cpp_int) (rand() % (max - min + 1)) + min;
    }

    return generated;
}

#endif