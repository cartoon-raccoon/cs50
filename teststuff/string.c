#include <stdio.h>

typedef char *string;

int main(void) {
    string greeting = "hello world";
    printf("%p\n", &greeting[0]);
    
}