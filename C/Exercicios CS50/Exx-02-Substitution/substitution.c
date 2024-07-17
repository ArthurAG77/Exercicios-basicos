#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void cryptograph (string argument);

int main (int argc, string argv[])
{
    int counter = 0;
    int duplicates = 0;

    if (argc == 1) //checks if the user give the program some input
    {
        printf("Type error, instead do: ./substitution key\n");
        return 1;
    }
    else if (argc != 2)
    {
        printf("To many arguments, submit just one command line\n"); // check if the user prompt just one command, if not get error and return 1
        return 1;
    }

    for (int i = 0; argv[1][i] != '\0'; i++) // loop that's go trought every char in the alphabet that the user give
    {
        counter++; // counts if the user gived 26 letters

        if (!isalpha(argv[1][i])) // check if the prompt is just alphabetical if not, return error
        {
            printf("Must only contain alphabetic characters\n");
            return 1;
            break;
        }
    }

    if (counter != 26) // checks if the counter (number of chars that user give to the program) is == 26, if not return error
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]) - 1; i++)
    {
        for (int j = i + 1; j < strlen(argv[1]); j++) // compare each char in the prompt
        {
            if (argv[1][i] == argv[1][j])
            {
                duplicates++; // checks for duplicate chars on the user prompt
            }
        }
    }

    if (duplicates > 0) // conditional if duplicates exists return error
    {
        printf("Must not contain duplications.\n");
        return 1;
    }

    cryptograph(argv[1]); // call a func that cryptograph the user prompt

    return 0;
}

void cryptograph (string argument)
{
    string plaintext = get_string("Plaintext: "); // get text to be substituted
    char cipher;
    char *encrypted = malloc((strlen(plaintext) + 1) * sizeof(char));

    for (int i = 0; i < strlen(plaintext); i++)
    {
        int index_lower = plaintext[i] - 'a'; // get index from every letter in plaintext in relaction to alphabet
        int index_upper = plaintext[i] - 'A'; // same but upper

        if (isupper(plaintext[i]))
        {
            cipher = toupper(argument[index_upper]);
            encrypted[i] = cipher; // if char is upper add the new equivalent char to a list, or better a string
        }
        else if (islower(plaintext[i]))
        {
            cipher = tolower(argument[index_lower]);
            encrypted[i] = cipher; // if char is lower add the new equivalent char to a list, or better a string
        }
        else
        {
            encrypted[i] = plaintext[i]; // If char is numbers or puncts just add to the string
        };
    }

    int end = strlen(plaintext);
    encrypted [end] = '\0'; // add the end to the string

    printf("%s\n", encrypted); // show on the terminal
}
