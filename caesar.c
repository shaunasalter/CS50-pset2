#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

void encode(int shift, string message);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int shift = atoi(argv[1]);
        if (shift > 0)
        {
            string message = GetString();
            encode(shift, message);
            return 0;
        }
        else
        {
            printf("This program only accepts non-negative values for the key.\n");
            return 2;
        }
    }
    else
    {
        printf("Please enter at least one and only command line argument!\n");
        return 1;
    }
}

void encode(int shift, string message)
{
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        int ascii_value = (int) message[i];
        if (ascii_value > 64 && ascii_value < 91)
        {
            message[i] = (char) ((ascii_value - 65 + shift) % 26 + 65);
        }
        else if (ascii_value > 96 && ascii_value < 123)
        {
            message[i] = (char) ((ascii_value - 97 + shift) % 26 + 97);
        }
    }
    printf("%s\n", message);
}
