#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void readlevel(string text); // call the function

int main(void)
{
    string ask = get_string("Text: ");
    readlevel(ask);
}

void readlevel(string text) // function that calc the number of letters, words and sentences, and do
                            // the index formula to see the grade
{
    int words = 1, letters = 0,
        sentences = 0; // counter variables, *notice that words starts with 1, this counter need to
                       // start with 1 to consider the last word in a text
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i])) // verify if the char in the string is alphabetic
        {
            letters++; // if true add 1 to letters counter (that count how many letters the code
                       // have)
        }
        else if (isblank(text[i])) // verify for blank spaces and consider a new word
        {
            words++; // if true add 1 to words counter  (that counts how many words have in the
                     // text)
        }
        else if (text[i] == '.' || text[i] == '?' ||
                 text[i] == '!') // check for sentences ends puncts
        {
            sentences++; // if true add 1 to sentences counter
        };
    }

    float l = (float) letters / words * 100;
    float s = (float) sentences / words * 100;
    float index = 0.0588 * l - 0.296 * s - 15.8; // index calc
    index = round(index);                        // round the index calc result

    if (index < 1) // statment for grades < 1
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16) // statment for grades > 16
    {
        printf("Grade 16+\n");
    }
    else // general grades:
    {
        printf("Grade %.0f\n", index);
    };
}
