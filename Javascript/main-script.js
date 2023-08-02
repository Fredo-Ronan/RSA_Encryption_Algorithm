/*
    This javascript source code is the example of implementation of those script modules including
    how to import and what to import in the main script

    © Author Fredo Ronan
*/

import { generate_prime } from './prime-number-op.js';
import { find_x_of_n, generate_private_key, generate_public_key } from './public_key_private_key.js';
import { decrypt_data, encrypt_data } from './encrypt-decrypt.js';

let p = generate_prime(100, 200);
let q = generate_prime(100, 200);

while(q===p){
    q = generate_prime(100, 200);
}

let n = p * q;

let x_of_n = find_x_of_n(p, q);

let public_key = generate_public_key(x_of_n);
let private_key = generate_private_key(x_of_n, public_key);

console.log('Public Key     : ' + public_key);
console.log('Private Key    : ' + private_key);
console.log('N Value        : ' + n);
console.log('X_of_n Value   : ' + x_of_n);

// Example message data that want to encrypt
let messageText = "Hello what's up!!";

console.log('Before Encrypt : ' + messageText);

//Encryption ===================================================================================================
let encrypted_message = encrypt_data(public_key, n, messageText); //return array of encrypted chunks of data 

console.log('After Encrypt  : ' + encrypted_message.join('')); //use join method from javascript default array method to convert to string

//Decryption ===================================================================================================
let encrypted_data = encrypted_message.join('');

let decrypted_data = decrypt_data(encrypted_data, private_key, n); //return array of decrypted/result of charaters that already decode

console.log('Decrypted      : ' + decrypted_data.join('')); //use join to convert to string without comma
