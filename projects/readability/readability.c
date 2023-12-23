#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *message = get_string("Text: ");
    int count_letters = 0;
    int count_words = 1;
    int count_sentences = 0;
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        if (isalpha(message[i]) != 0)
        {
            count_letters++;
        }
        else if (isblank(message[i]) != 0)
        {
            count_words++;
        }
        else if (message[i] == '.' || message[i] == '!' || message[i] == '?')
        {
            count_sentences++;
        }
    }

    float L = (float) count_letters / (float) count_words * 100.0;
    float S = (float) count_sentences / (float) count_words * 100.0;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}