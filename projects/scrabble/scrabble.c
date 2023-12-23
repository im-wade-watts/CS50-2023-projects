#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int compute_score(string word);
void print_winner(int score1, int score2);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    print_winner(score1, score2);
}

int compute_score(string word)
{
    int points = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (toupper(word[i]) == alphabet[j])
            {
                points += POINTS[j];
            }
        }
    }
    return points;
}

void print_winner(int score1, int score2)
{
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}