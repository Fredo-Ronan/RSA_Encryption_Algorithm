/*
    This is the main class for RSA Encryption Javascript module

    © Author Fredo Ronan
*/

import { generate_prime } from './prime-number-op.js';
import { find_x_of_n, generate_private_key, generate_public_key } from './public_key_private_key.js';
import { decrypt_data, encrypt_data } from './encrypt-decrypt.js';


export class RSAEncryption {

    #p_value;
    #q_value;
    #n_value;
    #x_of_n;
    #private_key;
    #public_key;

    constructor(minPrimeNumber, maxPrimeNumber){
        this.#p_value = generate_prime(minPrimeNumber, maxPrimeNumber);
        this.#q_value = generate_prime(minPrimeNumber, maxPrimeNumber);

        while(this.#q_value===this.#p_value){
            this.#q_value = generate_prime(minPrimeNumber, maxPrimeNumber);
        }

        this.#n_value = this.#calculate_n();
        this.#x_of_n = this.#calculate_x_of_n();
        this.#public_key = this.#calculate_public_key();
        this.#private_key = this.#calculate_private_key();
    }

    // Public Methods ================================================================
    get_public_key(){
        return this.#public_key;
    }

    get_n_value(){
        return this.#n_value;
    }


    // ENCRYPTION SIDE //////////////////////////////////////////////////////////////
    encrypt_array_result(text){
        return encrypt_data(this.#public_key, this.#n_value, text);
    }

    /* 
        To encrypt with the return of string with separator

        Example:

        encrypt_string_result(message, '|');
        That code will return the result like this ===> 8298|19209|910241|83982|8283|92763| (just example) 
    */
    encrypt_string_result(text, separator){
        let temp_encrypted = encrypt_data(this.#public_key, this.#n_value, text);
        let encrypted_data = temp_encrypted.join(separator);
        encrypted_data += separator;
        return encrypted_data;
    }


    // DECRYPTION SIDE //////////////////////////////////////////////////////////////
    decrypt_array_result(encrypted_data){
        return decrypt_data(encrypted_data, this.#private_key, this.#n_value, 'NULL');
    }

    decrypt_string_result(encrypted_data, separator){
        let temp_decrypted = decrypt_data(encrypted_data, this.#private_key, this.#n_value, separator);
        let decrypted_data = temp_decrypted.join('');
        return decrypted_data;
    }


    // Private Methods ================================================================
    #calculate_n(){
        return (this.#p_value * this.#q_value);
    }

    #calculate_x_of_n(){
        return find_x_of_n(this.#p_value, this.#q_value);
    }

    #calculate_public_key(){
        return generate_public_key(this.#x_of_n);
    }

    #calculate_private_key(){
        return generate_private_key(this.#x_of_n, this.#public_key);
    }
}