#!/usr/bin/python3
def minOperations(n):
    if (n <= 1):   # l do nothing, 0 or negative nothing can be done
        return 0
    
    half = int(n / 2)
    max = 1

    for i in range(2, half):
        if (n % i == 0):
            if (i > max):
                max = i

    if max != 1:
        return int(n / max) + max
    else:
        return n
