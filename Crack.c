#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>

int inc(char *c);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("ERROR: NO VALID ARGUMENT COUNT\n");
        return 1;
    }

    int maxLength = 5;

    char *crypt();
    char *hash = argv[1];
    char *c = malloc((maxLength + 1) * sizeof(char));
    char salt[3];
    memcpy(salt, hash, 2);
    salt[2] = '\0';

    for (int i = 1; i <= maxLength; i++)
    {
        for (int j = 0; j < i; j++)
        {
            c[j] = 'a';
        }

        c[i] = 0;
        do
        {
            if (strcmp(crypt(c, salt), hash) == 0)
            {
                printf("%s\n", c);
                free(c);
                return 0;
            }
        } 
        while (inc(c));
    }

    free(c);
    printf("ERROR: NO PASS FOUND\n");
    return 2;
}

int inc(char *c)
{
    if (c[0] == 0)
    {
        return 0;
    }
    if (c[0] == 'z')
    {
        c[0] = 'A';
        return 1;
    }
    if (c[0] == 'Z')
    {
        c[0] = 'a';
        return inc(c + sizeof(char));
    }
    c[0]++;
    return 1;
}