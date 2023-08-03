# Simple Javascript RSA Encryption Algorithm Implementation
This is the simple implementation of RSA Encryption Algorithm in Javascript using OOP principle

## Set Up
- First download this repository/clone this repository.<br>
  You can [download here](https://github.com/Fredo-Ronan/RSA_Encryption_Algorithm/archive/refs/heads/main.zip)<br>
  Or you can git clone using this command below
  ```
  git clone https://github.com/Fredo-Ronan/RSA_Encryption_Algorithm.git
  ```
- See the tree structure from the main README file of this repository [click here](https://github.com/Fredo-Ronan/RSA_Encryption_Algorithm/tree/main#tree-structure-of-this-repository)
- By learning the tree structure, copy the ``Main Javascript Module Folder`` into your project directory.<br>
  _This is recommended tree structure of your project after copying the Javascript module folder_
  ```
  .
  └── Your_root_project_directory/
      ├── RSAEncryption <---- Main Javascript Module Folder that copied into your project directory
      ├── your_other.html
      ├── your_other.js
      ├── your_other.css
      └── your_other_subfolder
  ```
- Import the module into your main ``script.js`` like this code below
  ```Javascript
  import { RSAEncryption } from './RSAEncryption/RSAEncryption.js';
  ```
- Use the module by creating an instance object of RSAEncryption class like this code below
  ```Javascript
  import { RSAEncryption } from './RSAEncryption/RSAEncryption.js';

  let rsa = new RSAEncryption(100, 200);

  /*
    100 means the minimum random prime number that later will generate by this class
    200 means the maximum random prime number that later will generate by this class

    Those parameters doesn't has to be a prime number,
    just take random range of number with the position of minimum number first, then the maximum number.
  */
  ```
- After create an instance, you can simply use the ``encrypt`` methods and ``decrypt`` methods from that instance to encrypt and decrypt the message/data.

## Example code
This is the example code to encrypt ``Hello bro`` sentence and decrypt it again.
```Javascript
import { RSAEncryption } from './RSAEncryption/RSAEncryption.js';

let rsa = new RSAEncryption(100, 200);

let message = "Hello bro";

let encrypted = rsa.encrypt_string_result(message, '|');
console.log(encrypted);

let decrypted = rsa.decrypt_string_result(encrypted, '|');
console.log(decrypted);
```
