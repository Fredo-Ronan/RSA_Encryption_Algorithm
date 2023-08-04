#ifndef DECRYPT_H
#define DECRYPT_H

#include "linked_list.h"
#include "./public_private_key_math/public_private_key_generator.h"
#include "./public_private_key_math/math_operation/power_of.h"

#include <string>
#include <cmath>

address parse_encrypted_data(std::string encrypted_data){
    
    address list_of_encrypted = NULL;
    std::string buffer = "";

    for(int i = 0; i<encrypted_data.length(); i++){
        if(encrypted_data[i] != '|'){
            buffer += encrypted_data[i];
        } else {
            int data = std::stoi(buffer);
            insertNode(alocate((cpp_int) data), &list_of_encrypted);
            buffer.clear();
        }
    }

    return list_of_encrypted;
}

std::string decrypt(std::string encrypted_data, cpp_int private_key, cpp_int n_value){
    address list_parsed_data = parse_encrypted_data(encrypted_data);
    address list_decrypted_data = NULL;
    std::string decrypted_text;

    while(list_parsed_data != NULL){
        // cpp_int decrypted_code = (cpp_int) pow((double) list_parsed_data->data, (double) private_key) % n_value;
        cpp_int decrypted_code = power_of(list_parsed_data->data, private_key) % n_value;
        // std::cout << decrypted_code << std::endl;
        char ch = (char) decrypted_code;
        decrypted_text += ch;
        list_parsed_data = list_parsed_data->next;
    }

    // std::cout << decrypted_text << std::endl;

    return decrypted_text;
}


#endif