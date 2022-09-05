#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long card = get_long("Number: ");

    long long firstCounter = 0;
    long long secondCounter = 0;
    long long total = 0;
    int isReal = 0;
    int brand = card / 1000000000000;


    //Verifies if the card is real or not (if the card is all 0's, next sttep will make it invalid)
    while (card >= 1)
    {
        int firstSequence = card % 10;
        int secondSequence = card % 100 / 10 * 2;
        card = card / 100;

        firstCounter += firstSequence ;
        if (secondSequence > 9)
        {
            secondSequence = (secondSequence % 10 + secondSequence / 10);
        }

        secondCounter += secondSequence;
    }
    total = firstCounter + secondCounter;
    if (total % 10 == 0)
    {
        isReal = 1;
    }

    //Verifies what brand is the card
    if (isReal == 1)
    {
        if (brand <= 9)
        {
            (brand == 4) ? printf("VISA\n") : printf("INVALID\n");

        }
        else if (brand >= 1000)
        {
            if (brand / 1000 == 4)
            {
                printf("VISA\n");
            }
            else if (brand / 100 >= 51 && brand / 100 <= 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }

        }
        else if (brand < 1000)
        {
            (brand / 10 == 34 || brand / 10 == 37) ? printf("AMEX\n") : printf("INVALID\n");

        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}