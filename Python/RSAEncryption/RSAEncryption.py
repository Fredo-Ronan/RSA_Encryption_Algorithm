"""
    Master Class

    make new instance of this class to make RSA Encryption work
"""

import sys
import os

path = os.getcwd() + '/RSAEncryption/public_key_private_key/'
pathMath = os.getcwd() + '/RSAEncryption/math_operation/'
path_encrypt_decrypt = os.getcwd() + '/RSAEncryption/encrypt_decrypt/'
sys.path.append(os.path.abspath(path))
sys.path.append(os.path.abspath(pathMath))
sys.path.append(os.path.abspath(path_encrypt_decrypt))

from RSAEncryption.public_key_private_key.public_private_key_generator import *
from RSAEncryption.math_operation.primeNumberOp import *
from RSAEncryption.encrypt_decrypt.DecryptRSA import *
from RSAEncryption.encrypt_decrypt.EncryptRSA import *


class RSA:

    """
        Set the range of prime number from min to max
    """
    def __init__(self, minPrimeNumber, maxPrimeNumber):
        self.__pValue = generatePrimeNumber(minPrimeNumber, maxPrimeNumber)
        self.__qValue = generatePrimeNumber(minPrimeNumber, maxPrimeNumber)

        while self.__qValue==self.__pValue:
            self.__qValue = generatePrimeNumber(minPrimeNumber, maxPrimeNumber)

        self.n_value = self.__calculate_n()
        self.__x_of_n = self.__calculate_x_of_n()
        self.public_key = self.__calculate_public_key()
        self.__private_key = self.__calculate_private_key()
    
    # Public methods =================================================================
    def get_n_value(self):
        return self.n_value

    def get_x_of_n(self):
        return self.__x_of_n

    def get_public_key(self):
        return self.public_key

    def __get_private_key(self):
        return self.__private_key

    """
        Return array of encrypted chunks of data
        use '|'.join(iterable) to make it converted to string with '|' for data separator

        EXAMPLE USAGE:

        encrypted = rsa_object_instance.encrypt(text)

        print(encrypted) <--- this will print in the form of array

        This code below will print in the form of string with '|' separator
        print('|'.join(str(data) for data in encrypted))

        #### OR you can store it in variable ####

        EXAMPLE:

        encrypted = '|'.join(str(data) for data in encrypted)
    """
    def encrypt(self, text):
        return encrypt_data(self.public_key, self.n_value, text)

    """
        Return array of decrypted characters

        same usage as encrypt method
    """
    def decrypt(self, data):
        return decrypt_data(data, self.__private_key, self.n_value)

    # Private methods ================================================================
    def __calculate_n(self):
        return (self.__pValue * self.__qValue)
    
    def __calculate_x_of_n(self):
        return find_x_of_n(self.__pValue, self.__qValue)

    def __calculate_public_key(self):
        return generate_public_key(self.get_x_of_n())

    def __calculate_private_key(self):
        return generate_private_key(self.get_x_of_n(), self.get_public_key())