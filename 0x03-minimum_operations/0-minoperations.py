#!/usr/bin/python3
def minOperations(n):
    if (n <= 1):   # l do nothing, 0 or negative nothing can be done*/
        return 0
    
    half = int(n / 2)
    for i in range(2, half + 2):
        if (n % i):
            return int(n / i) + i
