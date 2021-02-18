#!/usr/bin/python3

"""Checks if a data set represents a valid UTF-8 encoding"""


def validUTF8(data):
    """Checks for valid UTF-8 encoding"""
    byte_left = 0
    valid_enc = True

    for i in data:
        binary = str('{0:08b}'.format(i & 255))

        if (byte_left > 0):
            if len(binary) == 8 and binary[:2] == "10":
                byte_left -= 1
                continue
            else:
                valid_enc = False
                break

        if len(binary) == 8:
            if binary[0] == "0":
                pass
            elif binary[:3] == "110":
                byte_left = 1
            elif binary[:4] == "1110":
                byte_left = 2
            elif binary[:5] == "11110":
                byte_left = 3
            else:
                valid_enc = False
                break

    if byte_left != 0:
        valid_enc = False

    return valid_enc
