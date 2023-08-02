
import random

# Function to check is the number that given through the parameter is a prime number or not
# return value in boolean
def isPrime(number):
    if number < 2:
        return False
    
    i = 2

    while i < number // 2 + 1:
        if number%i == 0:
            return False
        i = i + 1

    return True


# Function to generate prime number from the given range from the parameter
# return value in number format like INT
def generatePrimeNumber(min, max):
    generated = random.randint(min, max)

    while not isPrime(generated):
        generated = random.randint(min, max)
    
    return generated
