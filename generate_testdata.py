from random import randint
from binascii import unhexlify, hexlify

#MAGIC NUMBER
MAX_FILES = 5

def generate_bytes(amount):
    """Generate 'amount' of random bytes"""
    return "".join([chr(randint(1,255)) for x in range(amount)])

for i in range(MAX_FILES):
    with open ("./input/testdata_{}.txt".format(i), "wb") as f:
        randtype = bytes(chr(randint(0,1)))
        cycles = generate_bytes(randint(5,10))
        seed = generate_bytes(randint(6,15))
        print(randtype, cycles, seed)
        
        data = randtype + bytes(chr(len(cycles))) + cycles + bytes(chr(len(seed))) + seed
        data = bytes(chr(len(data))) + data 
        print(repr(data))
        print(len(data))
        f.write(b"".join(data))
    
