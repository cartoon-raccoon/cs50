#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PLAINTXT_LEN 128

bool keyIsOk(char *key);

int main(int argc, char *argv[]) {
	char *key = argv[1];
	char *plaintxt = (char *) malloc(MAX_PLAINTXT_LEN * sizeof(char));

	if (argc != 2) {
		printf("Usage: ./substitution key\n");
		exit(1);
	}

	if (!keyIsOk(key)) {
		exit(1);
	}

	printf("plaintext: ");
	fgets(plaintxt, MAX_PLAINTXT_LEN, stdin);

	char *ciphertxt = "";

	int pletter;
	char cletter;
	for (int i = 0; i < strlen(plaintxt); i++) {
		pletter = (int) *(plaintxt+i);

		if (isupper(pletter)) {
			cletter = toupper(key[pletter-65]);
		}
		else if (islower(pletter)) {
			cletter = tolower(key[pletter-97]);
		}
		else {
			cletter = (char) pletter;
		}
		ciphertxt = strncat(ciphertxt, &cletter, 1);
	}

	printf("ciphertext: %s\n", ciphertxt);

	return 0;
}

bool keyIsOk(char *key) {

	if (strlen(key) != 26) {
		printf("Key must contain 26 characters.\n");
		return false;
	}

	for (int i = 0; i < 26; i++) {
		for (int j = i+1; j < 26; j++) {
			if (key[i] == key[j] || !isalpha(key[j])) {
				printf("Invalid key.\n");
				return false;
			}
		}
	}

	return true;
}
