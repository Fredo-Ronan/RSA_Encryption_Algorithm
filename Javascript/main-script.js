import { RSAEncryption } from './RSAEncryption/RSAEncryption.js';

let rsa = new RSAEncryption(100, 200);

let message = "Hello bro";

let encrypted = rsa.encrypt_string_result(message, '|');
console.log(encrypted);

let decrypted = rsa.decrypt_string_result(encrypted, '|');
console.log(decrypted);