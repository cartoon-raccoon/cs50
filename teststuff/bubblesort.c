#include <cs50.h>
#include <stdio.h>
//if element in qn is more than the one after it, swap them

void bubblesort(int arr[], int len);
void printArr(int arr[], int len);

int main(void) {
    int arr[10] = {3,5,1,7,4,2,9,6,8,0};
    int len = sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr, len);
    printArr(arr, len);
    printf("\n");
}

void bubblesort(int arr[], int len) {
    int n = len;
    if (n == 1) {
        return;
    }
    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1]) {
            int temp = arr[i+1]; //storing lesser no in separate var
            arr[i+1] = arr[i]; //moving larger no to right
            arr[i] = temp; //moving lesser no to left
        }
    }
    printf("\n");
    printArr(arr, n);
    bubblesort(arr, n-1);
}

void printArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%i", arr[i]);
    }
}