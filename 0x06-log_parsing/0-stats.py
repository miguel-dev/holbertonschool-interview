#!/usr/bin/python3
"""Reads stdin line by line and computes metrics"""

import sys
import traceback

if __name__ == "__main__":
    total_size = 0
    status_codes = {}
    num = 0

    try:
        for line in sys.stdin:
            parsed = line.split()
            total_size += int(parsed[-1])
            code = int(parsed[-2])

            if code in status_codes:
                status_codes[code] += 1
            else:
                status_codes[code] = 1

            num += 1

            if (num % 10 == 0):
                print("File size: {:d}".format(total_size))

                for c in sorted(status_codes):
                    print("{:d}: {:d}".format(c, status_codes[c]))

    except KeyboardInterrupt:
        print("File size: {:d}".format(total_size))

        for c in sorted(status_codes):
            print("{:d}: {:d}".format(c, status_codes[c]))

        raise

    finally:

        print("File size: {:d}".format(total_size))

        for c in sorted(status_codes):
            print("{:d}: {:d}".format(c, status_codes[c]))
