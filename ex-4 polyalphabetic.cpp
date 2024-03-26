#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenereEncrypt(char *plaintext, char *keyword, char *ciphertext) {
    int i, j;
    int keywordLength = strlen(keyword);
    int plaintextLength = strlen(plaintext);

    for (i = 0, j = 0; i < plaintextLength; i++, j++) {
        if (j == keywordLength)
            j = 0;

        if (isalpha(plaintext[i])) {
            int shift = tolower(keyword[j]) - 'a';
            if (isupper(plaintext[i]))
                ciphertext[i] = 'A' + (plaintext[i] - 'A' + shift) % 26;
            else if (islower(plaintext[i]))
                ciphertext[i] = 'a' + (plaintext[i] - 'a' + shift) % 26;
        } else {
            ciphertext[i] = plaintext[i];
            j--; 
        }
    }
    ciphertext[i] = '\0';
}

int main() {
    char plaintext[1000];
    char keyword[100];
    char ciphertext[1000];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter the keyword: ");
    scanf("%s", keyword);

    vigenereEncrypt(plaintext, keyword, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);
}
