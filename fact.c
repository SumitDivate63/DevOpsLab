#include <stdio.h>

// Recursive function to calculate factorial
unsigned long long factorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case: n! = n * (n - 1)!
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;
    
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Error handling for negative numbers
    if (num < 0) {
        printf("Error: Factorial of a negative number doesn't exist.\n");
    } else {
        printf("Factorial of %d = %llu\n", num, factorial(num));
    }

    return 0;
}