#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define UPPERCASE 1
#define LOWERCASE 0

string toCase(int choice, string toChange)
{
    string workstring = toChange;
    switch(choice)
    {
        case 0: //to lowercase
            for (int l = 0; l < strlen(workstring); l++)
            {
                if (isupper(workstring[l])) //when it encounters an uppercase, ignores lowercase
                {
                    workstring[l] = tolower(workstring[l]);
                }
            }
            return workstring;
            break;
        case 1: //to uppercase
            for (int l = 0; l < strlen(workstring); l++)
            {
                if (islower(workstring[l])) //when it encounters a lowercase, ignores uppercase
                {
                    workstring[l] = toupper(workstring[l]);
                }
            }
            return workstring;
            break;
        default:
            return "none";
            break;
    }

}

bool hasDuplicates(string key)
{
    string loweredKey = toCase(LOWERCASE, key); //standardizing case
    bool hasDupes = false;
    string ref = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < strlen(ref); i++) //looping over ref
    {
        int counter = 0;
        char checkChar = ref[i];
        for (int j = 0; j < strlen(loweredKey); j++)
        {
            if (loweredKey[j] == checkChar)
            {
                counter++;
            }
        }
        if (counter != 1) //if there is not exactly one occurrence per letter (i.e. duplicates)
        {
            hasDupes = true;
            break; //as long as there is one duplicate, key is invalid; no point checking the rest, save me some cpu cycles
        }

    }
    return hasDupes;
}

string substitution(string key, string message)
{
    string lowerRef = "abcdefghijklmnopqrstuvwxyz";
    string upperRef = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cipheredMessage = message;
    for (int i = 0; i < strlen(cipheredMessage); i++)
    {
        if (isalpha(cipheredMessage[i])) //filters out letters
        {
            if (isupper(cipheredMessage[i])) //filters out uppercase
            {
                string upKey = toCase(UPPERCASE, key);
                for (int j = 0; j < strlen(upperRef); j++)
                {
                    if (cipheredMessage[i] == upperRef[j]) //getting index of unciphered letter
                    {
                        cipheredMessage[i] = upKey[j]; //performing the substitution (uppercase)
                        break;
                    }
                }
            }
            else if (islower(cipheredMessage[i])) //filters out lowercase
            {
                string lowKey = toCase(LOWERCASE, key);
                for (int j = 0; j < strlen(lowerRef); j++)
                {
                    if (cipheredMessage[i] == lowerRef[j]) //getting index of unciphered letter
                    {
                        cipheredMessage[i] = lowKey[j]; //performing the substitution (lowercase)
                        break;
                    }
                }
            }
        }
    }
    return cipheredMessage;
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution [key]\n");
        exit(1);
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 alphabetical characters.\n");
        exit(1);
    }
    else if (hasDuplicates(argv[1]))
    {
        printf("Key contains duplicate letters.\n");
        exit(1);
    }
    else
    {
        string key = argv[1];
        string plaintext = get_string("plaintext: ");
        string ciphertext = substitution(key, plaintext);
        printf("ciphertext: %s\n", ciphertext);
        exit(0);
    }
}