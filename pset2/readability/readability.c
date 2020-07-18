#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int indexCalc(float letterCount, float wordCount, float sentCount)
{
    float L = (letterCount / wordCount) * 100;
    float S = (sentCount / wordCount) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int roundedIndex = round(index);
    return roundedIndex;
}

int main(int argc, string argv[])
{
    int lettercount = 0;
    //initializing word counter as 1 because the for loop does not account for the last word
    int wordcount = 1;
    int sentencecount = 0;
    string input = get_string("Text: ");
    //iterates over string and passes each char through a series of checks
    for (int i = 0; i < strlen(input); i++)
    {
        //letter check
        //if passes, skips the rest of the checks
        if (isalpha(input[i]))
        {
            lettercount++;
        }
        else //if char is not letter
        {
            switch (input[i])
            {
                case ' ': //check for spaces, spaces = words
                    wordcount++;
                    break;
                case '.': //next three cases check for sentence ending chars
                    sentencecount++;
                    break;
                case '!':
                    sentencecount++;
                    break;
                case '?':
                    sentencecount++;
                    break;
            }
        }
    }

    int index = indexCalc((float)lettercount, (float)wordcount, (float)sentencecount);
    printf("Letters: %i\nWords: %i\nSentences: %i\n", lettercount, wordcount, sentencecount);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}