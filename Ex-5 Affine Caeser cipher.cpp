#include <stdio.h>

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to check if two numbers are relatively prime (i.e., their GCD is 1)
int isRelativelyPrime(int a, int b) {
    return gcd(a, b) == 1;
}

int main() {
    // Check limitations on the value of b
    int b;
    printf("Enter the value of b: ");
    scanf("%d", &b);
    if (!isRelativelyPrime(b, 26)) {
        printf("The value of b must be co-prime with 26 for one-to-one encryption.\n");
    } else {
        printf("The value of b satisfies the co-prime condition.\n");
    }

    // Determine which values of a are not allowed
    printf("Values of a that are not allowed:\n");
    for (int a = 1; a < 26; a++) {
        if (!isRelativelyPrime(a, 26)) {
            printf("%d\n", a);
        }
    }

    return 0;
}

