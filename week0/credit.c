#include <cs50.h>
#include <stdio.h>
#include <math.h>

long get_positive(void);
long getfirstdigit (long cardnumber);
int checknum(long number);
long getseconddigit(long cardnumber);

int main(void)
{
    long cardnumber = get_positive();
    int ndigits = checknum(cardnumber);
    long firstdigit = getfirstdigit(cardnumber);
    long seconddigit = getseconddigit(cardnumber);

    // AMEX 15 ndigits (start with 34 or 37)
    if (ndigits == 15 && (firstdigit == 3 && (seconddigit == 4 || seconddigit == 7))) {
        printf("AMEX\n");
    }

    // mastercard 16 ndigits (start with 51, 52, 53, 54, or 55)
    else if (ndigits == 16 && (firstdigit == 5 && (seconddigit == 1 || seconddigit == 2 || seconddigit == 3 || seconddigit == 4 || seconddigit == 5))) {
        printf("MASTERCARD\n");
    }
    //visa 13 16 ndigits (start with 4)
    else if ((ndigits == 13 || ndigits == 16) && (firstdigit == 4)) {
        printf("VISA\n");
    }
    else {
        printf("INVALID\n");
    }

    // checksum Luhn's algorithm

}

long get_positive(void)
{
    long number;
    do
    {
    number = get_long("Card Number:  ");
    }
    while (number < 1);
    return number;
}

int checknum(long number)
{
    int i = 0;
    while (number > 0) {
        number /= 10;
        i++;
    }
    return i;
}

long getfirstdigit(long cardnumber)
{
    long firstdigit = cardnumber;
    while (firstdigit >= 10)
    {
        firstdigit /= 10;
    }
    return firstdigit;
}

long getseconddigit(long cardnumber)
{
    long seconddigit = cardnumber;
    while (seconddigit >= 100)
    {
        seconddigit /= 10;
    }
    return seconddigit % 10;
}

