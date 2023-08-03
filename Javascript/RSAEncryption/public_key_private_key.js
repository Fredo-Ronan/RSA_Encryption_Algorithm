
/*
    HANDLE GENERATION OF PUBLIC KEY AND PRIVATE KEY
*/

import { euclidGCD } from "./euclidGCD.js";

/* 
    Function to generate public key
    return int OR kind of number format

    Error code flag -1
*/
export function generate_public_key(x_of_n){
    for(let i = 3; i<x_of_n; i++){
        if(euclidGCD(i, x_of_n) === 1){
            return i;
        }
    }

    return -1;
}


/*
    Function to generate private key
    return int OR kind of number format

    Error code flag -1
*/ 
export function generate_private_key(x_of_n, public_key){
    for(let pk = 3; pk<=x_of_n; pk++){
        if((public_key * pk) % x_of_n === 1){
            return pk;
        }
    }

    return -1;
}


/*
    Function to find x_of_n function in math concept
    Some call in Phi_of_n, well it's basically just a mathematical function like for example: x(n)

    x(n) is the result of calculate the first random prime number substract by 1 multiply by second random prime number substract by 1

    Mathematical expression: x(n) = (firstPrime - 1) * (secondPrime - 1)

    This x(n) is use to produce the public key and private key using mod inverse method principle

    ====================================================================================
    return int OR kind of number format

    Error code flag -1
*/
export function find_x_of_n(p, q){
    return (p - 1) * (q - 1);
}