#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. Declare a file pointer
    FILE *fptr; 
    char buffer[100];

    // --- WRITING TO A FILE ---
    // Open the file in write mode ("w")
    fptr = fopen("example.txt", "w");

    // Always check if the file opened successfully
    if (fptr == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    // Write formatted text into the file
    fprintf(fptr, "Hello, World!\n");
    fprintf(fptr, "This is a basic C File I/O example.\n");
    fprintf(fptr, "Data persistence is useful.\n");

    // Close the file after writing to flush buffers and save data
    fclose(fptr);
    printf("Data successfully written to example.txt\n\n");


    // --- READING FROM A FILE ---
    // Open the file in read mode ("r")
    fptr = fopen("example.txt", "r");

    // Always check if the file exists/opened successfully
    if (fptr == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    printf("Reading contents from example.txt:\n");
    printf("----------------------------------\n");

    // Read and print line-by-line until the end of the file (NULL)
    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        printf("%s", buffer);
    }

    // Close the file to free system resources
    fclose(fptr);

    return 0;
}
