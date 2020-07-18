#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}
node;

int main(void)
{
    node *list == NULL;
    node *n = malloc(sizeof(node));
    n->value = 2;
    n->next = NULL;
    list = n;


}
