#include <cs50.h>
#include <stdio.h>

int get_positive(void);
int quarters(int cents);
int dimes(int cents);
int nickels(int cent);
int pennies(int cent);

int main(void)
{
    // prompt user for change
    int cents = get_positive();

    //calculate quarts
    int change_quarts = quarters(cents);
    cents = cents - change_quarts * 25;

   //calculate dimes
    int change_dimes = dimes(cents);
    cents = cents - change_dimes * 10;

   //calculate nickels
    int change_nickels = nickels(cents);
    cents = cents - change_nickels * 5;

   //calculate pennies
    int change_pennies = pennies(cents);
    cents = cents - change_pennies * 1;

    // print the total
    int total = change_quarts + change_dimes + change_nickels + change_pennies;
    printf("%i\n", total);
}

int get_positive(void)
{
    int cents;
    do
    cents = get_int("Change owed: ");
    while (cents < 0);
    return cents;
}

int quarters(int cents)
{
    int numquarts = cents / 25;
    return numquarts;
}

int dimes(int cents)
{
    int numdimes = cents / 10;
    return numdimes;
}

int nickels (int cents)
{
    int numnick = cents / 5;
    return numnick;
}

int pennies(int cents)
{
    return cents;
}
