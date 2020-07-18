#include <stdio.h>
#include <cs50.h>

void printp(int height);

int main(void) {
    int height = get_int("Height: ");
    printp(height);
    return 0;
}

void printp(int height) {
    if (height == 0) {
        return;
    }
    printp(height-1);
    for (int i = 0; i < height; i++) {
        printf("#");
    }
    printf("\n");
}