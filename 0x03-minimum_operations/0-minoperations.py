#!/usr/bin/python3
'''MinOperations module'''


def minOperations(n):
    '''Calculates minimal number of operations for a given number'''
    if (n <= 1):   # l do nothing, 0 or negative nothing can be done
        return 0

    half = int(n / 2)
    maxx = 1

    for i in range(2, half):
        if (n % i == 0):
            if (i > maxx):
                maxx = i

    if maxx != 1:
        return int(n / maxx) + maxx
    else:
        return n
