#!/usr/bin/python3
"""Reads stdin line by line and computes metrics"""

import sys
import traceback

if __name__ == "__main__":
    total_size = 0
    status_codes = {}
    num = 0

    def printMetrics():

        print("File size: {:d}".format(total_size))

        for c in sorted(status_codes):
            if status_codes[c]:
                print("{:s}: {:d}".format(c, status_codes[c]))

    try:
        for line in sys.stdin:
            parsed = line.split()

            if len(parsed) >= 2:
                code = parsed[-2]
                if code in status_codes:
                    status_codes[code] += 1
                else:
                    status_codes[code] = 1

                total_size += int(parsed[-1])

                num += 1

                if (num % 10 == 0):
                    printMetrics()
        printMetrics()

    except KeyboardInterrupt:
        printMetrics()
        traceback.print_exc()
