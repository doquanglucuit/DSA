import numpy as np
import time

for i in range (0, 10):
    inputFile = 'sort' + str(i) + '.inp'
    with open(inputFile, 'r') as fileInp:
        line = fileInp.readline()

        arr = np.fromstring(line, dtype=float, sep=' ')

        tic = time.time()
        arr = np.sort(arr)
        toe = time.time()

        print(int((toe - tic) * 1000))