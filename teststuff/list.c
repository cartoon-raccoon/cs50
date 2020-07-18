#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //allocating memory for and populating list
    int *list = malloc(sizeof(int)*3);
    list[0] = 11;
    list[1] = 22;
    list[2] = 33;

    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }

    int *newarr = realloc(list, sizeof(int)*4);
    if (newarr == NULL)
    {
        printf("ran outta memory; nullpointerexcept.");
        return 1;
    }

    //copying contents of list to newarr
    for (int i = 0; i < 3; i++)
    {
        newarr[i] = list[i];
    }

    //adding new element to newarr
    newarr[3] = 44;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", newarr[i]);
    }

    free(newarr);
}