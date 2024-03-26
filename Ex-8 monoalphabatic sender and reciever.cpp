#include <stdio.h>
#include <string.h>
#include <ctype.h>
void generateCipherSequence(char keyword[], char cipherSequence[]) {
    int lenKeyword = strlen(keyword);
    int alphabet[26] = {0}; 
    int index = 0;
    for (int i = 0; i < lenKeyword; i++) {
        char ch = toupper(keyword[i]);
        if (isalpha(ch) && !alphabet[ch - 'A']) {
            cipherSequence[index++] = ch;
            alphabet[ch - 'A'] = 1; 
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!alphabet[ch - 'A']) {
            cipherSequence[index++] = ch;
        }
    }
    cipherSequence[26] = '\0'; 
}
void encryptMonoalphabetic(char plaintext[], char cipherSequence[], char ciphertext[]) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        char ch = toupper(plaintext[i]);
        if (isalpha(ch)) {
            ciphertext[i] = isupper(plaintext[i]) ? cipherSequence[ch - 'A'] : tolower(cipherSequence[ch - 'A']);
        } else {
            ciphertext[i] = plaintext[i]; 
        }
    }
    ciphertext[len] = '\0'; 
}

int main() {
    char keyword[] = "CIPHER";
    char plaintext[] = "hello world"; 
    char cipherSequence[27]; 
    char ciphertext[100]; 
    generateCipherSequence(keyword, cipherSequence);
    encryptMonoalphabetic(plaintext, cipherSequence, ciphertext);
    printf("Generated Cipher Sequence: %s\n", cipherSequence);
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

