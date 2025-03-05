#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a string to an int
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string text = get_string("plaintext: ");
    printf("ciphertext: ");

    // For each character in the plaintext:
    for (int i = 0; i < strlen(text); i++)
    {
        // Rotate the character if it's a letter
        char c = rotate(text[i], key);   
        printf("%c", c);
    }
    printf("\n");
    return 0;
}

bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    // Keep key in range 0-25
    n = n % 26;

    // Handle uppercase letters
    if (isupper(c))
    {
        return ((c - 'A' + n) % 26) + 'A';
    }
    // Handle lowercase letters
    else if (islower(c))
    {
        return ((c - 'a' + n) % 26) + 'a';
    }
    // Return non-letters unchanged
    return c;
}
