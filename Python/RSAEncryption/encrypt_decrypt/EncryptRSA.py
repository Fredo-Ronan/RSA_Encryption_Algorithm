
def power_of(number, power):
    result = 1
    while power > 0:
        result = result * number
        power = power - 1
    
    return result


def encrypt_data(public_key, N_value, text):

    array_of_encrypted = []

    for ch in text:
        # You can choose to use power_of function or pow function by uncomment and comment these code below
        # result = power_of(int(ord(ch)), int(public_key)) % int(N_value)
        result = pow(int(ord(ch)), int(public_key), int(N_value))
        array_of_encrypted.append(result)

    return array_of_encrypted

