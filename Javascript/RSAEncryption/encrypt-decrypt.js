
import { power_of, power_of_BigInt } from "./math-operation.js";

// ENCRYPTION SIDE ==============================================================================================
/*
    Function to encrypt data/text data
*/
export function encrypt_data(public_key, N_value, text){

    let encrypted = []; // for debugging only

    for(let i = 0; i<text.length; i++){
        encrypted.push(power_of(text.charCodeAt(i), public_key) % N_value);
    }

    return encrypted;
}


// DECRYPTION SIDE ==============================================================================================
/*
    Function to parse encrypted data

    return array of int OR kind of array of number format
*/
export function parse_encrypted_data(encrypted_data, separator){
    let encrypted_data_array = [];
    let buffer = [];

    for(let i = 0; i<encrypted_data.length; i++){
        if(encrypted_data.charAt(i) != separator){
            buffer.push(encrypted_data.charAt(i));
        } else {
            let bufferStr = buffer.join('');
            
            if(bufferStr.charAt(0) == ','){
                encrypted_data_array.push(
                    parseInt(bufferStr.slice(1).concat('n')) // using BigInt format
                );
            } else {
                encrypted_data_array.push(
                    parseInt(bufferStr.concat('n')) // using BigInt format
                );
            }

            buffer = [];
        }
    }

    return encrypted_data_array;
}

/*
    Function to decrypt data/text data

    Accept parameter separator if the encrypted data has separator code for separating each encrypted data
    If it's doesn't have separator OR in the form of an array, fill the separator parameter with 'NULL'

    return array of decoded characters
*/
export function decrypt_data(encrypted_data, private_key, N_value, separator){
    let parsed_encrypted_data = [];
    let decrypted_data = [];

    if(separator != 'NULL'){
        parsed_encrypted_data = parse_encrypted_data(encrypted_data, separator);
    } else {
        parsed_encrypted_data = encrypted_data;
    }
    

    parsed_encrypted_data.forEach(data => {
        let result_decrypted = power_of_BigInt(BigInt(data), BigInt(private_key)) % BigInt(N_value);

        let final_result_decrypted = Number(result_decrypted);
        decrypted_data.push(String.fromCharCode(final_result_decrypted));
    })

    return decrypted_data;
}