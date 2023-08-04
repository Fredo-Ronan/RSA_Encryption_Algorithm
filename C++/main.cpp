
#include <iostream>
#include "./RSAEncryption/RSAEncryption.hpp"

using namespace std;

int main(){

    RSAEncryption rsa(100, 200);

    string message;

    cout << "Masukkan kalimat yang ingin di enkripsi: ";
    getline(cin, message);

    string encrypted = rsa.encrypt_return_string(message);
    cout << "Encrypted: " << encrypted << endl;

    string decrypted = rsa.decrypt_return_string(encrypted);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}