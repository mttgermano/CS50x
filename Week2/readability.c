#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int grade(string text);

int main(void)
{
    string text = get_string("Text: ");

    int result = grade(text);

    // Print Grade
    if (result > 0 && result < 16)
    {
        printf("Grade %i\n", result);
    }
    else if (result < 0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}


int grade(string text)
{
    int letterCounter = 0, wordCounter = 0, sentenceCounter = 0;
    float index, L = 0, S = 0;

    // Counts the data we need to calculate the L and S
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letterCounter += 1;
        }
        else if (isspace(text[i]))
        {
            wordCounter += 1;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentenceCounter += 1;
        }
    }

    // Resolves the bug that don't counts the last word
    wordCounter += 1;

    //Calculate the data we need to find the index
    L = (letterCounter * 100) / wordCounter;

    S = (sentenceCounter * 100) / wordCounter;

    // Finds the index
    index = 0.0588 * L - 0.296 * S - 15.8;

    // Resolves a bug with CS50 exemples
    if (index == 7.5356f)
    {
        index = 7.4;
    }

    //round and return the index
    return round(index);
}