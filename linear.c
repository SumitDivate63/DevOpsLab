#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    // Loop through every element in the array
    for (int i = 0; i < size; i++) {
        // If the target element is found, return its index
        if (arr[i] == target) {
            return i;
        }
    }
    // Return -1 if the element is not present in the array
    return -1;
}

int main() {
    int arr[] = {12, 45, 2, 8, 33, 71, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the number to search: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Call the search function
    int result = linearSearch(arr, size, target);

    // Output the final result
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}