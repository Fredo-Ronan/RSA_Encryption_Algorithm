# Simple OOP Python Implementation of RSA Encryption Algorithm
Just use the RSAEncryption folder and import it to the header of python code

## Set Up🛠️
Copy the ``RSAEncryption`` folder into your project directory folder.<br><br>
Recommended Tree Structure
```
.
└── Your_project_directory/
    ├── RSAEncryption/
    │   └── many_stuff_inside_RSAEncryption_library
    └── your_main_python_code.py
```

import and use the class ferom the module/library

```Python
from RSAEncryption.RSAEncryption import RSA # import the RSA class from this module/library

# make instance object of RSA class
rsa = RSA(100, 200)

"""
  RSA class constuctor accept 2 parameter:
  minimum prime number and maximum prime number

  These numbers will be used for the constructor to choose a random prime number between the 2 minimum and maximum reference numbers.
  And both always different.

  After that, the constructor immediately calculate the n value, x(n) value, public key and private key also. 
"""
```

## Example Usage⚙️
This is the example usage of RSAEncryption library for encrypting ``Hello brooo`` sentence with random prime number generate between 100 and 200.
```Python
from RSAEncryption.RSAEncryption import RSA

rsa = RSA(100, 200) # make instance object of RSA class

messageText = "Hello brooo" # example message to encrypt

# encrypt part ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
encrypted = rsa.encrypt(messageText) # encrypt the message using encrypt method from RSA class
# this code above also has an array return data type OR list data type

encryptedText = '|'.join(str(data) for data in encrypted) # convert array into string with '|' separator between the encrypted data

print(encryptedText) # if it's successfully work, it will print ----> 6318|7744|138|138|8205|9713|8806|22888|8205|8205|8205|



# decrypt part ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
decrypted = rsa.decrypt(encryptedText) # decrypt the encrypted string of data using decrypt method from RSA class
# this code above also has an array return data type OR list data type

decryptedText = ''.join(str(data) for data in decrypted) # convert array into string without separator ('')

print(decryptedText) # if it's succesfully work, it will print -----> Hello brooo
```

Actually it's quite short code, this code below is the same original code but without comments
```Python
from RSAEncryption.RSAEncryption import RSA

rsa = RSA(100, 200)

messageText = "Hello brooo"
encrypted = rsa.encrypt(messageText)
encryptedText = '|'.join(str(data) for data in encrypted)
print(encryptedText)

decrypted = rsa.decrypt(encryptedText)
decryptedText = ''.join(str(data) for data in decrypted)
print(decryptedText)
```
