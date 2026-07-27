#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50

// Define a structure to store developer data
typedef struct {
    int id;
    char name[MAX_NAME];
    float experience;
} Developer;

// Function prototype for input validation
int get_validated_int(const char *prompt);

int main() {
    FILE *file;
    Developer *dev;
    
    // 1. Allocate dynamic memory for the structure
    dev = (Developer *)malloc(sizeof(Developer));
    if (dev == NULL) {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    printf("--- Developer Registration System ---\n");

    // 2. Safely capture integers with validation
    dev->id = get_validated_int("Enter Developer ID (numbers only): ");

    // 3. Safely capture string data (preventing buffer overflow)
    printf("Enter Developer Name: ");
    fgets(dev->name, MAX_NAME, stdin);
    dev->name[strcspn(dev->name, "\n")] = '\0'; // Remove trailing newline character

    // 4. Capture floating-point data
    printf("Enter Years of Experience: ");
    while (scanf("%f", &dev->experience) != 1 || dev->experience < 0) {
        printf("Invalid input. Enter a valid number for experience: ");
        while (getchar() != '\n'); // Clear buffer
    }
    while (getchar() != '\n'); // Clear remaining newline

    // 5. File I/O operations (Saving data to disk)
    file = fopen("developers.txt", "a");
    if (file == NULL) {
        perror("Error opening file");
        free(dev);
        return EXIT_FAILURE;
    }

    fprintf(file, "ID: %d | Name: %s | Experience: %.1f years\n", dev->id, dev->name, dev->experience);
    fclose(file);

    // 6. Output confirmation from memory
    printf("\n[Success] Developer profile saved successfully!\n");
    printf("Profile Preview -> ID: %d, Name: %s, Exp: %.1f years\n", dev->id, dev->name, dev->experience);

    // 7. Always free dynamically allocated memory to prevent leaks
    free(dev);
    
    return EXIT_SUCCESS;
}

// Function to enforce numeric-only integer inputs
int get_validated_int(const char *prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) {
        printf("Invalid input. Please enter numbers only: ");
        while (getchar() != '\n'); // Purge the invalid characters from input stream
    }
    while (getchar() != '\n'); // Clear the newline
    return value;
}
