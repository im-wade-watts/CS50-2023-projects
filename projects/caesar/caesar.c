#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int correct_length(int array);
int encode(int key);
int decode(int key);

int main(int argc, string argv[])
{
    if (correct_length(argc) == 0)
    {
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int key = atoi(argv[1]);
    string f = get_string("do you want to encode or decode? ");
    if (strcmp(f, "encode") == 0)
    {
        return encode(key);
    }
    else if (strcmp(f, "decode") == 0)
    {
        return decode(key);
    }
    printf("Usage: ./caesar key\n");
    return 1;
}

int correct_length(int array)
{
    if (array != 2)
    {
        printf("Usage: ./caesar key\n");
        return 0;
    }
    return 1;
}

int encode(int key)
{
    string message = get_string("plaintext: ");
    printf("ciphertext: ");
    char final_message[strlen(message)];
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        int j = (int) message[i];
        while (key >= 26)
        {
            key -= 26;
        }
        if ((j >= 65 && j <= 90) || (j >= 97 && j <= 122))
        {
            j += key;
            if (j < 65 || (j > 90 && j < 97) || j > 122)
            {
                j -= 26;
            }
        }
        final_message[i] = (char) j;
        printf("%c", final_message[i]);
    }
    printf("\n");
    return 0;
}

int decode(int key)
{
    string message = get_string("ciphertext: ");
    printf("plaintext: ");
    char final_message[strlen(message)];
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        int j = (int) message[i];
        while (key >= 26)
        {
            key -= 26;
        }
        if ((j >= 65 && j <= 90) || (j >= 97 && j <= 122))
        {
            j -= key;
            if (j < 65 || (j > 90 && j < 97) || j > 122)
            {
                j -= 26;
            }
        }
        final_message[i] = (char) j;
        printf("%c", final_message[i]);
    }
    printf("\n");
    return 0;
}