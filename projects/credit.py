cardNumber = 0

while True:
    cardNumber = int(input("Card number: "))

    if cardNumber >= 0:
        break

# a card number above 16 digits is invalid
if cardNumber // 10000000000000000 > 0:
    print("INVALID")

else:
    digitsSum = 0
    otherNumSum = 0
    
    # selects the first four digits of card number
    digit16 = (cardNumber // 1000000000000000) % 10
    digit15 = (cardNumber // 100000000000000) % 10
    digit14 = (cardNumber // 10000000000000) % 10
    digit13 = (cardNumber // 1000000000000) % 10

    for i in range(16):
        # sums every other digit beginning with the last
        if i % 2 == 0:
            digitsSum += cardNumber % 10

        # sums the digits of 2 times every other digit
        # beginning with the second to the last
        else:
            b = cardNumber % 10
            b *= 2

            if b >= 10:
                otherNumSum += b // 10
                b %= 10

            otherNumSum += b

        cardNumber //= 10

    # total summation
    digitsSum += otherNumSum

    # total sum for a valid card is divisible by 10
    if digitsSum % 10 == 0:

        # VISA cards begin with 4 and are either 16 0r 13 digits long
        if(digit16 == 0 and digit13 == 4) or digit16 == 4:
            print("VISA")

        # AMEX cards begin with either 34 or 37 and are 15 digits long
        elif (digit16 == 0 and digit15 == 3) and (digit14 == 4 or digit14 == 7):
            print("AMEX")

        # MASTERCARDS begin with either 51 or 52
        # or 53 or 54 or 55 and are 16 digits long
        elif digit16 == 5 and (digit15 == 1 or digit15 == 2 or digit15 == 3 or digit15 == 4 or digit15 == 5):
            print("MASTERCARD")

        else:
            print("INVALID")

    else:
        print("INVALID")