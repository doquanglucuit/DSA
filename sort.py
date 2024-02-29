import numpy as np
import time
with open('sort.input', 'r') as fileInp:
    with open('sort.out', 'w') as fileOut:
        while True:
            f = fileInp.readline()
            if f == "":
                break
            line = list(map(float, f.split()))
    
            tic = time.time()
            line.sort()
            toe = time.time()

            print(int((toe - tic) * 1000))