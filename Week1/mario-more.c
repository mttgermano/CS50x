#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //For each line
    for (int i = 1; i <= height; i++)
    {
        //Print spaces
        for (int j = height; j > i; j--)
        {
            printf("%c", ' ');
        }

        //Print first sequence of #
        for (int k = 1; k <= i; k++)
        {
            printf("%c", '#');
        }
        //Print spaces between the sequences
        printf("  ");

        //Print second sequence of #
        for (int l = 1; l <= i; l++)
        {
            printf("%c", '#');
        }

        printf("\n");
    }
}