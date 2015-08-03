#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// prototype function
void print_initials(string name);

int main(void)
{
    string name = GetString();
    print_initials(name);
}

void print_initials(string name)
{
    if (name != NULL)
    {
        printf("%c", toupper(name[0]));
        for (int i = 0, n = strlen(name); i < n; i++)
        {
            if ((int) name[i] == 32)
            {
                printf("%c", toupper(name[i + 1]));
            }
        }
        printf("\n");
    }  
}
