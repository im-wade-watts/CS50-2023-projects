#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

int convert(char c);

int main(void)
{
    string h = get_string("Message: ");
    int length = strlen(h);
    int numbers[length];
    for (int i = 0; i < length; i++)
    {
        numbers[i] = convert(h[i]);
        for (int j = 0, n = 7; j < BITS_IN_BYTE; j++, n--)
        {
            if (numbers[i] >= pow(2, n))
            {
                printf("\U0001F7E1");
                numbers[i] -= pow(2, n);
            }
            else
            {
                printf("\U000026AB");
            }
        }
        printf("\n");
    }
}

int convert(char c)
{
    int bit = c;
    return bit;
}