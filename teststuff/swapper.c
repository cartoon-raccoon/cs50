#include <stdio.h>
#include <cs50.h>

void swap(int* xp, int* yp);

int main(void){
    int x = get_int("int x: ");
    int y = get_int("int x: ");
    printf("x is %i\ny = %i\n", x, y);
    swap(&x, &y);
    printf("x is %i\ny is %i\n", x, y);
    return 0;

}

void swap(int* xp, int* yp) {
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}