#ifndef ENCRYPT_H
#define ENCRYPT_H

#include "linked_list.h"
#include "./public_private_key_math/public_private_key_generator.h"
#include "./public_private_key_math/math_operation/power_of.h"

#include <string>
#include <cmath>

std::string encode_encrypted_to_string(address encrypted_data){
    address temp = encrypted_data;
    std::string encoded_text = "";

    while(temp != NULL){
        encoded_text += to_string(temp->data) + '|';
        temp = temp->next;
    }

    return encoded_text;
}

std::string encrypt(cpp_int public_key, cpp_int n_value, std::string text){
    
    address encrypted = NULL;

    for(int i = 0; i<text.length(); i++){
        cpp_int code = text[i];
        // std::cout << code << std::endl;
        cpp_int codeEncrypted = power_of(code, public_key) % n_value;
        // cpp_int codeEncrypted = (cpp_int) pow((double) code, (double) public_key) % n_value;
        // std::cout << codeEncrypted << std::endl;
        insertNode(alocate(codeEncrypted), &encrypted);
    }

    // printLinkedList<address>(encrypted);

    return encode_encrypted_to_string(encrypted);
}

#endif