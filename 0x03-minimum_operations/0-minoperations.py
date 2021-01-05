#!/usr/bin/python3
def minOperations(n):
    if (n <= 1):   # l do nothing, 0 or negative nothing can be done*/
        return 0
    elif n % 2:
        return int(n / 2) + 2
    elif n % 3:
        return int(n / 3) + 3
    elif n % 5:
        return int(n / 5) + 5
    elif n % 7:
        return int(n / 7) + 7
