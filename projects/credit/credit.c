#include <cs50.h>
#include <math.h>
#include <stdio.h>

long get_positive_number(void);
bool validation_of_car(long credit_car);
int how_many_digits(long credit_car);
void which_card(long credit_car, int count);

int main(void)
{
    long credit_car = get_positive_number();
    bool isValid = validation_of_car(credit_car);
    if (isValid)
    {
        int count = how_many_digits(credit_car);
        which_card(credit_car, count);
    }
    else
    {
        printf("INVALID\n");
    }
}

long get_positive_number(void)
{
    long n;
    do
    {
        n = get_long("Number: ");
    }
    while (n < 1);
    return n;
}

bool validation_of_car(long credit_car)
{
    bool isAlternate = false;
    int i = 0;
    int sum = 0;
    while (i < credit_car)
    {
        if (isAlternate)
        {
            int digit = (credit_car % 10) * 2;
            while (digit != 0)
            {
                sum += (digit % 10);
                digit = digit / 10;
            }
        }
        else
        {
            sum += (credit_car % 10);
        }
        credit_car = credit_car / 10;
        isAlternate = !isAlternate;
    }
    if (sum % 10 == 0)
    {
        return true;
    }
    return false;
}

int how_many_digits(long credit_car)
{
    int count = 0;
    while (credit_car > 0)
    {
        count += 1;
        credit_car = credit_car / 10;
    }
    return count;
}

void which_card(long credit_car, int count)
{
    int first_two_digits = credit_car / pow(10, count - 2);
    if (count == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        printf("AMEX\n");
    }
    else if (count == 16 && (first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 || first_two_digits == 54 ||
                             first_two_digits == 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((count == 13 || count == 16) && first_two_digits / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}