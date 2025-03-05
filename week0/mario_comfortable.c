#include <stdio.h>
#include <cs50.h>

int get_positive(void);
void print_row(int height);

int main(void)
{
    int height = get_positive();
    print_row(height);
}

int get_positive(void)
{
    int height;
    do
    height = get_int("what's the height of the pyramid? ");
    while (height < 1 || height > 8);
    return height;
}

void print_row(int height)
{
    int space, row, collumn;
    for (row = 0; row < height; row++)
    {
        //left space
        for (space = 0; space < height - row - 1; space++) {
        printf(" ");
        }

        // left hashes
        for (collumn = 0; collumn <= row; collumn++) {
        printf("#");
        }

        // double space
        printf("  ");

        //right hashes
        for (collumn = 0; collumn <= row; collumn++) {
        printf("#");
        }

        //next line
        printf("\n");
    }
}

