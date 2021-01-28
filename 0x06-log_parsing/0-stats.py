#!/usr/bin/python3
"""Reads stdin line by line and computes metrics"""

import sys
import traceback

if __name__ == "__main__":
    total_size = 0
    status_codes = {"200": 0,
                    "301": 0,
                    "400": 0,
                    "401": 0,
                    "403": 0,
                    "404": 0,
                    "405": 0,
                    "500": 0}
    num = 0

    def printMetrics():

        print("File size: {:d}".format(total_size))

        for c in sorted(status_codes):
            if status_codes[c]:
                print("{:s}: {:d}".format(c, status_codes[c]))

    try:
        for line in sys.stdin:
            parsed = line.split()

            if len(parsed):
                code = parsed[-2]
                if code in status_codes:
                    status_codes[code] += 1

                total_size += int(parsed[-1])

                num += 1

                if (num % 10 == 0):
                    printMetrics()
        printMetrics()

    except KeyboardInterrupt:
        printMetrics()
        raise
