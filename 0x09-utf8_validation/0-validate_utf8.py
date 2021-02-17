#!/usr/bin/python3

"""Checks if a data set represents a valid UTF-8 encoding"""


def validUTF8(data):
    for i in data:
        if i > 255:
            return False
    return True
