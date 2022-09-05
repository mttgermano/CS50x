from cs50 import get_int
height = get_int("Height: ")

while(height not in range(1,9)):
    height = int(input("Height: "))

for i in range(1, height + 1):
    for j in range(height, i, -1):
        print(" ",end="")

    for k in range(1, i + 1):
        print("#",end="")

    print("  ",end="")

    for l in range(1, i + 1):
        print("#",end="")

    print("")