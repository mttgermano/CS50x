from cs50 import get_string

def grade(text):
    dici = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
    letterCounter = 0
    wordCounter = 0
    sentenceCounter = 0
    index = 0
    Lconst = 0
    Sconst = 0


    # Counts the data we need to calculate the L and S
    for i in range(0,len(text)):
        if (text[i] in dici):
            letterCounter += 1

        elif (text[i] == " "):
            wordCounter += 1

        elif (text[i] == '.' or text[i] == '!' or text[i] == '?'):
            sentenceCounter += 1

    # Resolves the bug that don't counts the last word
    wordCounter += 1

    #Calculate the data we need to find the index
    Lconst = (letterCounter * 100) / wordCounter

    Sconst = (sentenceCounter * 100) / wordCounter

    # Finds the index
    index = 0.0588 * Lconst - 0.296 * Sconst - 15.8

    #round and return the index
    return round(index)


text = get_string("Text: ")

result = grade(text)

if (result > 0 and result < 16):
    print(f"Grade {result}\n")

elif (result < 0):
    print("Before Grade 1\n")

else:
    print("Grade 16+\n")