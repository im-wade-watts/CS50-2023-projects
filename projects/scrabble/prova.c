#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

void combert_to_lower(string word);

int main(void)
{
    string a = "HoLaJaJa";
    combert_to_lower(a);
}

void combert_to_lower(string word)
{
    int length_word = strlen(word);
    char w[length_word];

    for (int i = 0, n = length_word; i < n; i++)
    {
        w[i] = tolower(word[i]);
    }
    printf("%c%c%c%c%c%c%c%c%c",w[0],w[1],w[2],w[3],w[4],w[5],w[6],w[7],w[8]);
}
