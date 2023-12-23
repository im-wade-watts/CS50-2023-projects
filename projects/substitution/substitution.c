#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool check_autentification(char n_letters[], char letter);
void decode(string argv[]);
void encode(string argv[]);
int validate_key(int argc, string argv[]);

int main(int argc, string argv[])
{
    int isvalid = validate_key(argc, argv);
    if (isvalid == 1)
    {
        return 1;
    }
    string what_to_do = get_string("encode or decode? ");
    if (strcmp(what_to_do, "encode") == 0)
    {
        encode(argv);
    }
    else if (strcmp(what_to_do, "decode") == 0)
    {
        decode(argv);
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

int validate_key(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    char n_letters[26];
    for (int i = 0; i < 26; i++)
    {
        if (isdigit(argv[1][i]) || !isalnum(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        argv[1][i] = tolower(argv[1][i]);
        if (check_autentification(n_letters, argv[1][i]))
        {
            printf("Key must not contain repeated characters\n.");
            return 1;
        }
        n_letters[i] = argv[1][i];
    }
    return 0;
}

bool check_autentification(char n_letters[], char letter)
{
    for (int i = 0; i < 26; i++)
    {
        if (n_letters[i] == letter)
        {
            return true;
        }
    }
    return false;
}

void encode(string argv[])
{
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        int j = plaintext[i];
        if (j >= 65 && j <= 90)
        {
            j -= 65;
            printf("%c", toupper(argv[1][j]));
        }
        else if (j >= 97 && j <= 122)
        {
            j -= 97;
            printf("%c", argv[1][j]);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

void decode(string argv[])
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string plaintext = get_string("ciphertext: ");
    printf("plaintext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        int j = plaintext[i];
        if (j >= 65 && j <= 90)
        {
            for (int k = 0; k < 26; k++)
            {
                // printf("AAAAAAA %c\n", argv[1][k]);
                if (toupper(argv[1][k]) == plaintext[i])
                {
                    printf("%c", alphabet[k]);
                }
            }
        }
        else if (j >= 97 && j <= 122)
        {
            for (int k = 0; k < 26; k++)
            {
                if (argv[1][k] == plaintext[i])
                {
                    printf("%c", tolower(alphabet[k]));
                }
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}