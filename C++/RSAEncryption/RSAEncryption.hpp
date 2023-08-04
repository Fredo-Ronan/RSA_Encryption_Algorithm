/*
   Master class

   Make an instance of this class to make the RSA Encryption work

   Author: Fredo Ronan
*/


#include "./includes/encrypt.h"
#include "./includes/decrypt.h"
#include "./includes/public_private_key_math/math_operation/primeNumberOp.h"
#include "./includes/public_private_key_math/public_private_key_generator.h"


class RSAEncryption {
   private:
      cpp_int p_value;
      cpp_int q_value;
      cpp_int n_value;
      cpp_int x_of_n;
      cpp_int public_key;
      cpp_int private_key;

      cpp_int calculate_n(){
         return (p_value * q_value);
      }

      cpp_int calculate_x_of_n(){
         return find_x_of_n(p_value, q_value);
      }

      cpp_int calculate_public_key(){
         return generate_public_key(x_of_n);
      }

      cpp_int calculate_private_key(){
         return generate_private_key(x_of_n, public_key);
      }

      void init(cpp_int minPrimeNumber, cpp_int maxPrimeNumber){
         p_value = generatePrimeNumber(minPrimeNumber, maxPrimeNumber);
         q_value = generatePrimeNumber(minPrimeNumber, maxPrimeNumber);

         while(q_value==p_value){
            q_value = generatePrimeNumber(minPrimeNumber, maxPrimeNumber);
         }

         n_value = calculate_n();
         x_of_n = calculate_x_of_n();
         public_key = calculate_public_key();
         private_key = calculate_private_key();
      }

   public:
      /*
         "Accept cpp_int data type"

         Minimum and maximum range of prime number

         NOTE: doesn't have to be prime number, but later the constructor
               will automatically generate prime number
      */
      RSAEncryption(cpp_int minPrimeNumber, cpp_int maxPrimeNumber){
         init(minPrimeNumber, maxPrimeNumber);
      }

      /*
         "Accept int data type"

         Minimum and maximum range of prime number

         NOTE: doesn't have to be prime number, but later the constructor
               will automatically generate prime number
      */
      RSAEncryption(int minPrimeNumber, int maxPrimeNumber){
         init((cpp_int) minPrimeNumber, (cpp_int) maxPrimeNumber);
      }

      // Encrypt side =========================================================
      std::string encrypt_return_string(std::string text){
         return encrypt(public_key, n_value, text);
      }

      void encrypt_show_imediately(std::string text){
         std::string encrypted_data = encrypt(public_key, n_value, text);
         std::cout << "Encrypted ===> " << encrypted_data << std::endl;
      }


      // Decrypt side =========================================================
      std::string decrypt_return_string(std::string encrypted_text){
         return decrypt(encrypted_text, private_key, n_value);
      }

      void decrypt_show_imediately(std::string encrypted_text){
         std::string decrypted_data = decrypt(encrypted_text, private_key, n_value);
         std::cout << "Decrypted ===> " << decrypted_data << std::endl;
      }

      // Data access side =========================================================
      cpp_int get_public_key(){
         return public_key;
      }

      cpp_int get_n_value(){
         return n_value;
      }
};
