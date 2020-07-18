#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    string number;
    //infinite loop until customer cooperates
    while (true)
    {
        bool valid = true;
        number = get_string("Number: ");
        for (int i = 0; i < strlen(number); i++)
        {
            if (number[i] < 48 || number[i] > 57)
            {
                valid = false;
            }
        }
        if (valid)
        {
            break;
        }
    }

    //declaring vars that we need
    bool valid = false;
    int arr1[(strlen(number) / 2) + 1];
    int arr2[(strlen(number) / 2) + 1];
    int counter1 = 0;
    int counter2 = 0; //number of valid elements in half-length array

    //splitting the number by every other digit
    for (int i = strlen(number) - 2; i > -1; i -= 2)
    {
        arr1[counter1] = 2 * (number[i] - 48);
        counter1++;
    }
    //getting the digits not read in the first loop
    for (int i = strlen(number) - 1; i > -1; i -= 2)
    {
        arr2[counter2] = number[i] - 48;
        counter2++;
    }

    //summing digits for each number in arr1 and then summing the entire thing
    int sum = 0;
    for (int i = 0; i < counter1; i++)
    {
        //directly increments sum if number is single digit
        if (arr1[i] < 10)
        {
            sum += arr1[i];
        }
        else
        {
            int tempsum = 0;
            int remain;
            while (arr1[i] != 0)
            {
                //extracting second digit to int remain
                remain = arr1[i] % 10;
                tempsum += remain;
                arr1[i] /= 10;
            }
            sum += tempsum;
        }
    }
    //adding the rest of the digits in arr2
    for (int i = 0; i < counter2; i++)
    {
        sum += arr2[i];
    }

    //does checksum pass?
    if (sum % 10 == 0)
    {
        valid = true;
    }
    //printf("%i\n", sum % 10);

    //flowchart for determining card issuer
    //if card passes checksum test
    if (valid && strlen(number) > 10)
    {
        if (number[0] == '3')
        {
            if (number[1] == '4' || number[1] == '7')
            {
                printf("AMEX\n");
            }
            else if (number[1] == '5')
            {
                printf("JCB\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (number[0] == '4')
        {
            printf("VISA\n");
        }
        else if (number[0] == '5' || number[0] == '2')
        {
            if (number[1] - 48 <= 5)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (number[0] == '6')
        {
            printf("DISCOVER\n");
        }
    }
    //if card fails checksum test or is too short
    else
    {
        printf("INVALID\n");
    }
    return 0;
}