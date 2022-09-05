from cs50 import get_int;

card = get_int("Number: ")

firstCounter = int(0)
secondCounter = int(0)
total = int(0)
isReal = int(0)
brand = int(card / 1000000000000)

while (card >= 1):
    firstSequence = int(card % 10)
    secondSequence = int(card % 100 / 10) * 2
    card = int(card / 100)

    firstCounter += firstSequence

    if (secondSequence > 9):
        secondSequence = int((secondSequence % 10 + secondSequence / 10))

    secondCounter += secondSequence

    total = firstCounter + secondCounter
    if total % 10 == 0:
        isReal = 1


if (isReal == 1):
    if (brand <= 9):
        if (brand == 4):
            print("VISA\n")
        else:
            print("INVALID\n")

    elif (brand >= 1000):

        if (int(brand / 1000) == 4):
            print("VISA\n")
        elif (int(brand / 100) >= 51 and int(brand / 100) <= 55):
            print("MASTERCARD\n")
        else:
            print("INVALID\n")

    elif (brand < 1000):
        if (int(brand / 10) == 34 or int(brand / 10) == 37):
            print("AMEX\n")
        else:
            print("INVALID\n")
    else:
        print("INVALID\n")
else:
    print("INVALID\n")