
# Function to find the GCD (Greatest Common Divisor) OR in indonesian => FPB (Faktor Persekutuan Terbesar)
# using euclid algorithm
# 
# Parameter m and n position is doesn't matter
# has return value of the GCD result in number format like INT
def euclidGCD(m, n):
    while n != 0:
        temp = m % n
        m = n
        n = temp

    return m