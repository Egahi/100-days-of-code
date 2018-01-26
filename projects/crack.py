# crack.py
# cracks passwords using brute force
# assumptions made
# 1. password contains only alphbets
# 2. maximum of 5 characters long
# @s_egahi
# this was crack

import sys
import string
import crypt

# ensure proper usage
if not len(sys.argv) == 2:
    print("Usage: ./crack k")
    exit(1)

else:
    salt = sys.argv[1][:4]

    # character string of length 1
    for c in list(string.ascii_letters):
        Hash = crypt.crypt(c, salt)
        if Hash == sys.argv[1]:
            print(c)
            exit(0)

    # character string of length 2
    for c in list(string.ascii_letters):
        for d in list(string.ascii_letters):
            Hash = crypt.crypt(c + d, salt)
            if Hash == sys.argv[1]:
                print(c + d)
                exit(0)

    # character string of length 3
    for c in list(string.ascii_letters):
        for d in list(string.ascii_letters):
            for e in list(string.ascii_letters):
                Hash = crypt.crypt(c + d + e, salt)
                if Hash == sys.argv[1]:
                    print(c + d + e)
                    exit(0)

    # character string of length 4
    for c in list(string.ascii_letters):
        for d in list(string.ascii_letters):
            for e in list(string.ascii_letters):
                for f in list(string.ascii_letters):
                    Hash = crypt.crypt(c + d + e + f, salt)
                    if Hash == sys.argv[1]:
                        print(c + d + e + f)
                        exit(0)

    # character string of length 5
    for c in list(string.ascii_letters):
        for d in list(string.ascii_letters):
            for e in list(string.ascii_letters):
                for f in list(string.ascii_letters):
                    for g in list(string.ascii_letters):
                        Hash = crypt.crypt(c + d + e + f + g, salt)
                        if Hash == sys.argv[1]:
                            print(c + d + e + f + g)
                            exit(0)


    print("NO MATCH!")

exit(0)
'''
anushree:50xcIMJ0y.RXo = YES
brian:50mjprEcqC/ts = CA
bjbrown:50GApilQSG3E2 =
lloyd:50n0AAUD.pL8g = lloyd
malan:50CcfIk1QrPr6 =
maria:509nVI8B9VfuA = TF
natmelo:50JIIyhDORqMU = nope
rob:50JGnXUgaafgc = ROFL
stelios:51u8F0dkeDSbY = NO
zamyla:50cI2vYkF0YU2 = LOL
'''