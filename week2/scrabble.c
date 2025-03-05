#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// the points of each boxes.
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int get_score(string wrd);
int main(void)
{
    // get user input
    string wrd1, wrd2;
    int sc1, sc2;
    wrd1 = get_string("Player 1:  ");
    wrd2 = get_string("player 2:  ");

    // get the score
    sc1 = get_score(wrd1);
    sc2 = get_score(wrd2);

    // congratulation text
    // if player 1 wins
    if (sc1 > sc2)
    {
        printf("Player 1 wins!\n");
    }
    else if (sc1 < sc2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Its a tie!\n");
    }
}

// to get the score from the input
int get_score(string wrd)
{
    int sc = 0;
    for (int i = 0, len = strlen(wrd); i < len; i++)
    {
        if (isupper(wrd[i]))
        {
            sc += POINTS[wrd[i] - 'A'];
        }
        else if (islower(wrd[i]))
        {
            sc += POINTS[wrd[i] - 'a'];
        }
    }
    return sc;
}
