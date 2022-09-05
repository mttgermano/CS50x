#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

string decrypt(string key, string text);

int main(int argc, string argv[])
{
    int alphanumeric = 0, duplicated = 0;
    string key = "  ";

    // Check if we have 2 arguments
    if (argc > 1)
    {
        key = argv[1];

        // Checks if the key has some not alphanumeric character
        for (int i = 0, len = strlen(key); i < len; i++)
        {
            if (isalpha(key[i]) == 0)
            {
                alphanumeric = 1;
            }
        }

        //Checks if the key has duplicated char in the key
        for (int j = 0, len = strlen(key); j < len; j++)
        {
            char char1 = key[j];
            for (int k = j + 1; k < len; k++)
            {
                if (char1 == key[k])
                {
                    duplicated = 1;
                    printf("%c\n", key[k]);
                }
            }
        }

    }
    else
    {
        key = argv[0];
    }

    // Checks if the key is valid
    if (argc != 2 || duplicated == 1)
    {
        printf("Usage: ./substitution key\n");

        return 1;
    }
    else if (strlen(key) < 26 || strlen(key) > 26)
    {
        printf("Key must contain 26 characters.\n");

        return 1;
    }
    else if (alphanumeric == 1)
    {
        printf("Key must only contain alphabetic characters.\n");

        return 1;
    }

    // Get a text to encrypt
    string text = get_string("plaintext: ");

    // Decrypt and print the ciphertext
    string result = decrypt(key, text);

    printf("ciphertext: %s\n", result);
}

string decrypt(string key, string text)
{
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isupper(text[i]))
        {
            text[i] = toupper(key[text[i] - 65]);    //65 is 'A' on ASCII table
        }
        else if (islower(text[i]))
        {
            text[i] = tolower(key[text[i] - 97]);    //97 is 'a' on ASCII table
        }
    }

    return text;
}