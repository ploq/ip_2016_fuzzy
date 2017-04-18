from random import randint
from binascii import unhexlify, hexlify

MAX_FILES = 1

def generate_bytes(amount):
    """Generate 'amount' of random bytes"""
    return [bytes([randint(93,255)]) for x in range(amount)]

for i in range(MAX_FILES):
    with open ("./input/testdata_{}.txt".format(i), "wb") as f:
        randtype = generate_bytes(1)
        cycles = generate_bytes(5)
        seed = generate_bytes(6)
        print(randtype, cycles, seed)
        
        data = randtype + [bytes([len(cycles)])] + cycles + [bytes([len(seed)])] + seed
        data = [bytes([len(data)])] + data 
        print(repr(data))
        print(len(data))
        f.write(b"".join(data))
    
