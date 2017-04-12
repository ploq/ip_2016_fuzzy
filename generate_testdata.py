from random import randint

MAX_FILES = 1;

def generate_bytes(amount):
    """Generate 'amount' of random bytes"""
    return "".join([chr(randint(1,255)) for x in range(amount)])

for i in range(MAX_FILES):
    with open ("./input/testdata_{}.txt".format(i), "ab") as f:
        randtype = generate_bytes(1)
        cycles = generate_bytes(5)
        seed = generate_bytes(6)
        data = randtype + chr(len(cycles)) + cycles + chr(len(seed)) + seed
        print(repr(data))
        print(len(data))
        f.write(data.encode())
    
