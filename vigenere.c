#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string encode(string keyword, string message);

int main(int argc, string argv[])
{
    // Only one command line argument accepted
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
            
            }
            else
            {
                printf("Please use only alphabet characters in keyword.\n");
                return 1;
            }
        }
        // prompt user for message to encode
        string plain_text = GetString();
        
        // encode message
        string cipher_text = encode(argv[1], plain_text);
        
        // print encoded message
        printf("%s\n", cipher_text);
        return 0;
    }
    else
    {
        printf("Enter one and only one command line argument please.\n");
        return 1;
    }
}

string encode(string keyword, string message)
{
    int index = 0;   
    int shift = 0;
    
    // loop over string (message) given by user
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        int j = index % strlen(keyword);
    
        // change to number values to do ascii math
        int message_ascii = (int) message[i];
        int keyword_ascii = (int) keyword[j];
        
        // initialize shift value depending on case (upper or lower)
        if (keyword_ascii > 64 && keyword_ascii < 91)
        {
            shift = keyword_ascii - 65;
        }
        else if (keyword_ascii > 96 && keyword_ascii < 123)
        {
            shift = keyword_ascii - 97;
        }
        
        // 
        if (message_ascii > 64 && message_ascii < 91)
        {
            message[i] = (char) ((message_ascii - 65 + shift) % 26 + 65);
            index++;
        }
        else if (message_ascii > 96 && message_ascii < 123)
        {
            message[i] = (char) ((message_ascii - 97 + shift) % 26 + 97);
            index++;
        }
    }
    return message;
}
