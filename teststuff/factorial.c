#include <stdio.h>
#include <cs50.h>

int factrl(int n);
int collatz(int n);

int main (int argc, string argv[]) {
    int n = get_int("Collatz: ");
    const int displayn = n;
    //int result = factrl(n);
    //printf("%i\n", result);
    int steps = collatz(n);
    printf("collatz took %i steps to reach 1 from %i\n", steps, displayn);
    return 0;
}

int factrl(int n) {
    if (n == 1) {
        return 1;
    }
    //here comes the r e c u r s i o n
    int fact = n * factrl(n-1);
    return fact;
}

int collatz(int n){
    if(n == 1) { //base case
        return 0;
    }
    else if (n % 2 == 0) { //even case
        return 1 + collatz(n/2);
    }
    else {
        return 1 + collatz((3*n)+1); //odd case
    }
}