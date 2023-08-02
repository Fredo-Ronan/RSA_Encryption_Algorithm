
import sys
import os

path = os.getcwd() + '/math_operation'

script_dir = os.path.dirname(__file__)
math_operation_module_dir = os.path.join(script_dir, path)
sys.path.append(os.path.abspath(math_operation_module_dir))

import euclidGCD
import math, random

def find_x_of_n(p, q):
    return (p - 1) * (q - 1)

def generate_public_key(x_of_n):
    seqNumber = 3

    while seqNumber < x_of_n:
        if euclidGCD.euclidGCD(seqNumber, x_of_n) == 1:
            return seqNumber
        seqNumber = seqNumber + 1


def generate_private_key(x_of_n, public_key):
    guess = 3

    while (public_key * guess)%x_of_n != 1 and guess <= x_of_n:
        guess = guess + 1
    
    return guess