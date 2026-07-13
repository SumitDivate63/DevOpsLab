#include <stdio.h>
#include <stdlib.h>

int main() {
    int r1, c1, r2, c2;

    // Input dimensions for the first matrix
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &r1, &c1);

    // Input dimensions for the second matrix
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Rule check: Columns of 1st matrix must equal rows of 2nd matrix
    if (c1 != r2) {
        printf("\nError! Multiplication not possible.\n");
        printf("The number of columns in the first matrix (%d) must equal the number of rows in the second matrix (%d).\n", c1, r2);
        return 1;
    }

    // Declare matrices with user-defined dimensions
    int first[r1][c1];
    int second[r2][c2];
    int result[r1][c2];

    // Input elements for the first matrix
    printf("\nEnter elements of the first matrix (%dx%d):\n", r1, c1);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &first[i][j]);
        }
    }

    // Input elements for the second matrix
    printf("\nEnter elements of the second matrix (%dx%d):\n", r2, c2);
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &second[i][j]);
        }
    }

    // Core Logic: Multiply matrices and initialize result matrix elements to 0
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0; // Reset element value before accumulation
            for (int k = 0; k < c1; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }

    // Display the final result matrix
    printf("\nResultant Product Matrix (%dx%d):\n", r1, c2);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n"); // New line after each row
    }

    return 0;
}
