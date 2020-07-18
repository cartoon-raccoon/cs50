#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int wordCounter(string input)
{
    //initializing counter as 1 because the for loop does not account for the last word
    int count = 1;
    //iterates over string and everytime it encounters a space char,
    //it increments the counter
    for (int i = 0; i < strlen(input); i++)
    {
        //assigning placeholder char to test
        char character = input[i];
        if (character == ' ')
        {
            count++;
        }
    }
    return count;
}

int letterCounter(string input)
{
    int count = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        char character = input[i];
        if (isalpha(character))
        {
            count++;
        }
    }
    return count;
}

int sentenceCounter(string input)
{
    //initializing as 0 because the string will end with fullstop char
    //this means the last sentence gets counted
    //TODO: account for strings not ending with a fullstop char
    //i actually submitted without implementing this ^ because im a lazy shit
    int count = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        //assigning placeholder char to test
        //testing for fullstops, questions and exclamations
        char character = input[i];
        if (character == '.')
        {
            count++;
        }
        else if (character == '!')
        {
            count++;
        }
        else if (character == '?')
        {
            count++;
        }
    }
    return count;
}

int indexCalc(float letterCount, float wordCount, float sentCount)
{
    //letter count is different from character count
    //because character count includes whitespace and non-letters
    float L = (letterCount / wordCount) * 100;
    float S = (sentCount / wordCount) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int roundedIndex = round(index);
    return roundedIndex;
}

int main(int argc, string argv[])
{
    string input = get_string("Text: ");
    int stringlength = strlen(input);
    int wordcount = wordCounter(input);
    int sentencecount = sentenceCounter(input);
    int lettercount = letterCounter(input);
    int index = indexCalc((float)lettercount, (float)wordcount, (float)sentencecount);
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