#!/usr/bin/python3

"""Checks if a data set represents a valid UTF-8 encoding"""


def validUTF8(data):
    """Checks for valid UTF-8 encoding"""
    byte_left = 0

    for i in data:
        binary = str('{0: 08b}'.format(i & 255))
        binary = binary[1:]

        if (byte_left > 0):
            if len(binary) == 8 and binary[0] == "1" and binary[1] == "0":
                byte_left -= 1
                continue
            else:
                return False

        if len(binary) == 8:
            if binary.find("110") == 0:
                byte_left = 1
            elif binary.find("1110") == 0:
                byte_left = 2
            elif binary.find("11110") == 0:
                byte_left = 3
            else:
                return False
    return True
