#include <cs50.h>
#include <stdio.h>


int main(void)
{
    //ask for the text
    text answer = get_string("text:  ");

}

int get_letter(string text)
{
    int numlet = 0;
    // iterate one letter at a time
    for (int i = 0; len = strlen(text); i < len; i++)
    {
        // check its an alphabet
        if(isalpha(text[i]) {
            numlet++;
        }
    }
    return numlet;
}

int get_word(string text) {
    int numwrd = 0;
    //check if there is even the length of the word/letter in the first place.
    if (strlen(text) == 0) {
        //if there isnt then its done.
        return = 0;
    }

    //now if there is then its going to continue
    for (int i = 0, len = strlen(text))
    if (text[i] == ' ') {
        numwrd++;
    }
    return numwrd;
}

