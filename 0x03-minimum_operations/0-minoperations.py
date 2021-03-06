#!/usr/bin/python3
'''MinOperations module'''


def minOperations(n):
    '''Calculates minimal number of operations for a given number'''
    if (n <= 1):
        return 0

    numOp = 0
    numH = 1
    mem = 0

    while (numH < n):
        if (n % numH == 0):
            mem = numH  # Copy All
            numOp += 1
        numH += mem  # Paste
        numOp += 1

    return numOp
