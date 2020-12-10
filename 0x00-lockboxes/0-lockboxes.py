#!/usr/bin/python3
def canUnlockAll(boxes):
    keys = []
    unlockAll = True
    for i in range(0, 2):
        unlockAll = True
        for number in range(0, len(boxes)):
            if (number == 0):
                for key in boxes[number]:
                    if key not in keys:
                        keys.append(key)
            elif (number not in keys):
                unlockAll = False
            else:
                for key in boxes[number]:
                    if key not in keys:
                        keys.append(key)
    return unlockAll
