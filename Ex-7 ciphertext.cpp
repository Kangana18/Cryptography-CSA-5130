#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to find the modular multiplicative inverse of a mod m
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // If inverse doesn't exist
}

// Function to decrypt the ciphertext using the given keys (a, b)
void decryptAffineCipher(char ciphertext[], int a, int b) {
    int n = strlen(ciphertext);
    for (int i = 0; i < n; i++) {
        if (isalpha(ciphertext[i])) {
            char ch = ciphertext[i];
            char decrypted;
            if (isupper(ch)) {
                decrypted = 'A' + ((modInverse(a, ALPHABET_SIZE) * (ch - 'A' - b + ALPHABET_SIZE)) % ALPHABET_SIZE);
            } else {
                decrypted = 'a' + ((modInverse(a, ALPHABET_SIZE) * (ch - 'a' - b + ALPHABET_SIZE)) % ALPHABET_SIZE);
            }
            printf("%c", decrypted);
        } else {
            printf("%c", ciphertext[i]); // Non-alphabetic characters remain unchanged
        }
    }
    printf("\n");
}

int main() {
    char ciphertext[] = "BUABUABUABUABUABUABUABU"; // Example ciphertext
    int freq[ALPHABET_SIZE] = {0}; // Array to store letter frequency
    int maxFreqIndex = 0, secondMaxFreqIndex = 0;

    // Calculate letter frequency
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            char ch = tolower(ciphertext[i]);
            freq[ch - 'a']++;
        }
    }

    // Find the most frequent and second most frequent letters
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (freq[i] > freq[maxFreqIndex]) {
            secondMaxFreqIndex = maxFreqIndex;
            maxFreqIndex = i;
        } else if (freq[i] > freq[secondMaxFreqIndex] && i != maxFreqIndex) {
            secondMaxFreqIndex = i;
        }
    }

    // Assuming 'B' corresponds to 'E' and 'U' corresponds to 'T' in the plaintext
    // Calculate the keys (a, b) for the affine cipher
    int a = (maxFreqIndex - 'E' + ALPHABET_SIZE) % ALPHABET_SIZE; // Assuming 'E' is the most frequent letter in English
    int b = (secondMaxFreqIndex - 'T' + ALPHABET_SIZE) % ALPHABET_SIZE; // Assuming 'T' is the second most frequent letter in English

    // Decrypt the ciphertext using the calculated keys
    printf("Assuming 'B' corresponds to 'E' and 'U' corresponds to 'T' in the plaintext:\n");
    decryptAffineCipher(ciphertext, a, b);

    return 0;
}

