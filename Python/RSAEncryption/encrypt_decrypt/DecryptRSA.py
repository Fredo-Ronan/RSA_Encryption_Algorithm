
def power_of(number, power):
    result = 1
    while power > 0:
        result = result * number
        power = power - 1
    
    return result

def parse_encrypted_data(encrypted_data):
    encrypted_data_array = []
    buffer = []

    for element in encrypted_data:
        if element != '|':
            buffer.append(element)
        else:
            bufferStr = ''.join(buffer)
            bufferNum = int(bufferStr)
            encrypted_data_array.append(bufferNum)
            buffer.clear()

    return encrypted_data_array

def decrypt_data(encrypted_data, private_key, N_value):
    parsed_encrypted_data = parse_encrypted_data(encrypted_data)
    decrypted_data = []

    for data in parsed_encrypted_data:
        # You can choose to use power_of function or pow function by uncomment and comment these code below
        # result_decrypted = power_of(int(data), int(private_key)) % int(N_value)
        result_decrypted = pow(int(data), int(private_key), int(N_value))
        
        decrypted_data.append(chr(result_decrypted))

    return decrypted_data