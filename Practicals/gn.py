import random
with open('numbers.txt','w') as f:
    for _ in range(500):
        f.write(str(random.randint(0,10000)) + '\n')