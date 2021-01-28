#!/usr/bin/python3
"""Reads stdin line by line and computes metrics"""

import sys
import traceback

if __name__ == "__main__":
    total_size = 0
    status_codes = {}
    valid_codes = {"200", "301", "400", "401", "403", "404", "405", "500"}
    num = 0

    def printMetrics():

        print("File size: {:d}".format(total_size))

        for c in sorted(status_codes):
            print("{:s}: {:d}".format(c, status_codes[c]))

    try:
        for line in sys.stdin:
            parsed = line.split()

            if len(parsed) != 9:
                continue

            try:
                total_size += int(parsed[-1])
            except ValueError:
                continue

            code = parsed[-2]

            if code not in valid_codes:
                continue

            num += 1

            if code in status_codes:
                status_codes[code] += 1
            else:
                status_codes[code] = 1

            if (num % 10 == 0):
                printMetrics()
        printMetrics()

    except KeyboardInterrupt:
        printMetrics()
        raise
