#include <stdio.h>
#include <ctype.h>

int main(void) {
    // char smth = 'z';
    // char highalphabet[26];
    // char lowalphabet[26];
    // for (int i = 0; i < 26; i++) {
    //     highalphabet[i] = (char)i+65;
    //     lowalphabet[i] = (char)i+97;
    // }
    // printf("%c\n", highalphabet[0]);
    // printf("%c\n", lowalphabet[0]);
    //int key = 1;
    //char ci = smth - 26-alphabet[(smth+key)%26];
    //printf("%c\n", ci);
    char *word = "zzrdvark";

    int l1 = (int) tolower(word[0]) - 97;
    int l2 = (int) tolower(word[1]) - 97;
    int digest = ((26 * l1) + l2);

    printf("%i\n", digest);
}