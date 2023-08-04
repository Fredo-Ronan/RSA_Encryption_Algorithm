# Simple RSA Encryption Algorithm implementation in C++
This is the library of simple implementation of RSA Encryption Algorithm using OOP principle that C++ support with.<br><br>
Just write this code at the top of your main code or at your main header file:<br>
```C++
#include "./RSAEncryption/RSAEncryption.hpp"
```
and you're ready to go :)<br><br> But read the NOTES down below first please....<br><br>

## Couple of NOTES for this programming language (this is impoertant to read)
- The ``main.cpp`` and ``main`` file was just an example implementation code of using that ``RSAEncryption`` library folder and not a part of the library.
- This particular programming langugae turns out not really support very big integer number, so it's require another external library in order to implement this algorithm. You can find the library called ``boost`` in the internet and download and also install it into your main C++ library file.<br><br>OR if you are on linux operating system, you can simply use the ``setup-boost-linux.sh`` file and run in using ``bash`` command on terminal to automate everything.
- **IMPORTANT NOTE** even though this library was using the ``boost`` library in order to get the C++ can handle the big number, it's still not versatile for a very very big integer number. Because if you force to run in very big integer number like for example:<br><br> ``748736473674827346203846203528309230948273985269378628937462039852367042834203895273087238476509237126319024123561923817238172541023894810238162974519275169219283719276941263192731028310286120381720489127587124705672461223498237592837198479385710841792865918236152598357613081724183520345872913746508375``<br><br> it wiil cause the program runs into SIGSEGV or Segmentation Fault signal or in other word, it crashed.


## Set Up
- First download this repository, you can [click here](https://github.com/Fredo-Ronan/RSA_Encryption_Algorithm/archive/refs/heads/main.zip).
- After download it, see the tree structure of how the file and folder was organize in this repository at the main README.md file of this repository. You can go [here](https://github.com/Fredo-Ronan/RSA_Encryption_Algorithm/tree/main#tree-structure-of-this-repository).
- By learning the structure, you will khow that for this particular programming language, go to ``C++`` folder and the just copy the ``RSAEncryption`` folder into your project directory folder.<br><br> The recommended tree structure of your project after copying the ``RSAEncryption`` folder is like this:<br>
```
.
└── Your_root_project_directory/
    ├── RSAEncryption <--- Copied RSAEncryption library for C++ inside your project directory
    ├── your_other.cpp
    ├── your_other_library
    ├── your_own_library
    └── your_header.hpp
```
- After that, you can simply add ``#include`` file in your header or at the top of your main cpp program.
- But don't forget to include the standart ``iostream`` library from C++ before add include this library.
  <br>Like this example:
  ```C++
  #include <iostream>
  #include "./RSAEncryption/RSAEncryption.hpp"
  ```

## Example usage
The example usage can be found on the ``main.cpp`` file included in this section of repository.<br><br>
But you can directly copy this also:
```C++
#include <iostream>
#include "./RSAEncryption/RSAEncryption.hpp" //include the library

using namespace std; //optional, but without this you must write cout, cin and other keyword follow by std::cout

int main(){

    RSAEncryption rsa(100, 200); //make an instance of RSAEncryption class

    string message;

    cout << "Masukkan kalimat yang ingin di enkripsi: "; //basically just prompting user to input text that she/he want to encrypt
    getline(cin, message);

    string encrypted = rsa.encrypt_return_string(message); //encrypt the message and return the result in string format
    cout << "Encrypted: " << encrypted << endl;

    string decrypted = rsa.decrypt_return_string(encrypted); //decrypt the encrypted string and return the result in decrypted string format
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
```
