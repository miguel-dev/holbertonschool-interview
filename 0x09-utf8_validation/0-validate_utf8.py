#!/usr/bin/python3

"""Checks if a data set represents a valid UTF-8 encoding"""


def validUTF8(data):
    for i in data:
        char_left = 0
        if i > 255:
            return False
        else:
            binary = str(bin(i))
            binary = binary[-8:]

            if (char_left > 0):
                if (binary[0] == 1 and binary[1] == 0):
                    char_left -= 1
                    continue
                else:
                    return False

            if binary.find("110") == 0:
                char_left = 1
            elif binary.find("1110") == 0:
                char_left = 2
            elif binary.find("11110") == 0:
                char_left = 3
    return True
