#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    while (true) //infinite loop until if statement passes
    {
        height = get_int("height: ");
        if (height <= 8 && height > 0)
        {
            break;
        }
    }
    
    //main for loop iterates over the rows
    //nested for loops iterate over individual elements of the pyramid
    for (int i = 1; i < height + 1; i++)
    {
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < height - (height - i); j++)
        {
            printf("#");
        }
        printf("  "); //prints whitespace in the middle
        for (int j = 0; j < height - (height - i); j++)
        {
            printf("#");
        }
        printf("\n");
    }
}