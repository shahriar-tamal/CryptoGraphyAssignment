#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void decrypt(char *cipher, char *key, char *msg) {
    int i;
    for (i = 0; cipher[i] != '\0'; i++) {
        msg[i] = ((cipher[i] - 'A') - (key[i] - 'A') + 26) % 26 + 'A';
    }
    msg[i] = '\0';
}

int main() {
    char message[100], key[100], cipher[100], decrypted[100];
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

    decrypt(cipher, key, decrypted);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}

