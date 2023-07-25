#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'climbingLeaderboard' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY ranked
#  2. INTEGER_ARRAY player
#

#https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

def climbingLeaderboard(ranked, player):
    # Write your code here
    p_rankes = []
    curr_place = 1
    player.reverse()
    ranked = list(dict.fromkeys(ranked))
    for score in player:
        while (curr_place <= len(ranked)) and (ranked[curr_place-1] > score):
            curr_place+=1
        p_rankes.append(curr_place)
    p_rankes.reverse()
    return p_rankes

if __name__ == '__main__':
    #fptr = open(os.environ['OUTPUT_PATH'], 'w')
    fptr = open("out.txt", 'w')

    ranked_count = int(input().strip())

    ranked = list(map(int, input().rstrip().split()))

    player_count = int(input().strip())

    player = list(map(int, input().rstrip().split()))

    result = climbingLeaderboard(ranked, player)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
