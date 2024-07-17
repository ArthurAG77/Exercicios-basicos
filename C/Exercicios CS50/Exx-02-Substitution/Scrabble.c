#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int num_players = 2;

struct PointValue
{
    int points;
    char chars[11];
};

int main(void)
{
    string players[num_players];
    int answer_digits[num_players];
    int sum_points = 0;
    int points_array[2];

    struct PointValue PointValues[7] = {
    {1, {'A', 'E', 'I', 'L', 'N', 'O', 'R', 'S', 'T', 'U'}},
    {2, {'D', 'G'}},
    {3, {'B', 'C', 'M', 'P'}},
    {4, {'F', 'H', 'V', 'W', 'Y'}},
    {5, {'K'}},
    {8, {'J', 'X'}},
    {10, {'Q', 'Z'}},
    };

    for (int i = 0; i < num_players; i++)
    {
        string ask = get_string("Player %i ", i + 1);
        int n = strlen(ask);
        players[i] = ask;
        answer_digits[i] = n;
    }

    for (int i = 0; i < num_players; i++)
    {
        sum_points = 0;
        for (int j = 0; j < answer_digits[i]; j++)
        {
            char upper = toupper(players[i][j]);
            for (int k = 0; k < 7; k++)
            {
                for (int l = 0; l < sizeof(PointValues[k].chars); l++)
                {
                    if (upper == PointValues[k].chars[l])
                    {
                        sum_points += PointValues[k].points;
                        break;
                    }
                }
            }
        }
        points_array[i] = sum_points;
    };

    if (points_array[0] > points_array[1])
    {
        printf("Player 1 wins!\n");
    }
    else if (points_array[0] == points_array[1])
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}
