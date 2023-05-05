#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void encrypt(char *msg, char *key, char *cipher) {
    int i;
    for (i = 0; msg[i] != '\0'; i++) {
        cipher[i] = ((msg[i] - 'A') + (key[i] - 'A')) % 26 + 'A';
    }
    cipher[i] = '\0';
}

int main() {
    char message[100], key[100], cipher[100];
    int i;

    printf("Enter message: ");
    fgets(message, 100, stdin);
    printf("Enter key: ");
    fgets(key, 100, stdin);

    srand(time(NULL));
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] == ' ') {
            cipher[i] = ' ';
        } else {
            cipher[i] = rand() % 26 + 'A';
        }
    }
    cipher[i] = '\0';

    encrypt(message, key, cipher);
    printf("Encrypted message: %s\n", cipher);

    return 0;
}

