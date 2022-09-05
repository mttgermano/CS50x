#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Get a name from the user
    string name = get_string("What's your name? ");
    //Prints the name
    printf("hello, %s\n", name);
}