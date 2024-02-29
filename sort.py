import numpy as np
import time
for i in range (0, 10):
    inputFile = 'sort' + str(i) + '.inp'
    with open(inputFile, 'r') as fileInp:
        line = list(map(float, fileInp.readline().split()))

        tic = time.time()
        line.sort()
        toe = time.time()

        print(int((toe - tic) * 1000))