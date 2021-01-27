#!/usr/bin/python3
"""Reads stdin line by line and computes metrics"""

import sys
import traceback

total_size = 0
status_codes = {}
num = 0

try:
    for line in sys.stdin:
        parsed = line.split()
        total_size += int(parsed[-1])
        code = parsed[-2]

        if code in status_codes:
            status_codes[code] += 1
        else:
            status_codes[code] = 1

        if (num % 10 == 0):
            print("File size: {:d}".format(total_size))

            for c in sorted(status_codes):
                print("{:s}: {:d}".format(c, status_codes[c]))

        num += 1

except KeyboardInterrupt:
    exc_info = sys.exc_info()
    print("File size: {:d}".format(total_size))

    for c in sorted(status_codes):
        print("{:s}: {:d}".format(c, status_codes[c]))

    traceback.print_exception(*exc_info)
    del exc_info

finally:
    print("File size: {:d}".format(total_size))

    for c in sorted(status_codes):
        print("{:s}: {:d}".format(c, status_codes[c]))
