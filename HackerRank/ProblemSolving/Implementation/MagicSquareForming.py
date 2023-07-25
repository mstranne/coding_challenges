#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'formingMagicSquare' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY s as parameter.
#

#https://www.hackerrank.com/challenges/magic-square-forming/problem?isFullScreen=true

#distinct means different !!!!
#so we always have the nums 1 - 9  in the 3x3 mat

possible_solutions = [
    [[8,1,6], [3,5,7], [4,9,2]],
    [[6,1,8], [7,5,3], [2,9,4]],
    [[4,9,2], [3,5,7], [8,1,6]],
    [[2,9,4], [7,5,3], [6,1,8]],
    [[8,3,4], [1,5,9], [6,7,2]],
    [[4,3,8], [9,5,1], [2,7,6]],
    [[6,7,2], [1,5,9], [8,3,4]],
    [[2,7,6], [9,5,1], [4,3,8]]
]
def formingMagicSquare(s):
    # Write your code here
    min_cost = 999
    for opt in possible_solutions :
        cost = 0
        for x in range(0,3):
            for y in range(0, 3):
                cost += abs(opt[x][y] - s[x][y])
        if(cost < min_cost):
            min_cost = cost

    return min_cost

if __name__ == '__main__':
    #fptr = open(os.environ['OUTPUT_PATH'], 'w')
    fptr = open("out.txt", 'w')

    s = []

    for _ in range(3):
        s.append(list(map(int, input().rstrip().split())))

    result = formingMagicSquare(s)

    fptr.write(str(result) + '\n')

    fptr.close()
