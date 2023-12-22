#include <cs50.h>
#include <stdio.h>

int get_blocks(void);
void build_stair(int n);

int main(void)
{
    int height = get_blocks();
    build_stair(height);
}

int get_blocks(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}

void build_stair(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k < n - i; k++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
