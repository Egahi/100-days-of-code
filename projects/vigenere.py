# vigenere.py
# encrypts an inputed text by a desired key
# @s_egahi
# this was vigenere

# needed to access agrv
import sys

# needed of get_string()
import cs50

# returns True for a key with only alphabetical characters
# aka valid keys, returns false otherwise


def validateKey():
    for c in sys.argv[1]:
        # non-alphabetical character invalidates the key
        if not c.isalpha():
            return False

    # key is valid
    return True

# shifts a character a number of places specified by a key


def encrypt():
    length = len(plainText)

    # track key characters to use
    keyIndex = 0

    for i in range(length):
        # encrypt only alphabetical characters
        if plainText[i].isalpha():
            keyLength = len(sys.argv[1])

            # ASCII value of key's i'th character
            key = ord(sys.argv[1][keyIndex % keyLength])

            # difference between ASCII and alphabetical index
            cDiff = 65 if sys.argv[1][keyIndex % keyLength].isupper() else 97

            # convert from ASCII to alphabetical index
            key -= cDiff

            # next character of key
            keyIndex += 1

            # difference between ASCII and alphabetical index
            pDiff = 65 if plainText[i].isupper() else 97

            # ASCII value of plainText's i'th character
            i_xter = ord(plainText[i])

            # convert from ASCII to alphabetical index
            coded = (((i_xter - pDiff) + key) % 26) + pDiff

            # update cipher
            cipherText[i] = chr(coded)


if not len(sys.argv) == 2:
    # ensure proper usage
    print("Usage: ./vigenere k")
    exit(1)

elif validateKey() == 0:
    # ensure key is valid
    print("Invalid key!")
    exit(1)

else:
    print("plaintext: ", end="")
    plainText = cs50.get_string()

    # ensure get_string() returns a string
    if plainText is None:
        exit(1)

    # convert string to list for concatenation purposes
    cipherText = list(plainText)
    encrypt()
    # update plainText with ciphers
    plainText = "".join(cipherText)

    print("ciphertext: " + plainText)

# success
exit(0)