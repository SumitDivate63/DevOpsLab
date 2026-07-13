#include<stdio.h>
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;
    
    // Outer loop for number of passes
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Reset flag for the current pass
        
        // Inner loop for adjacent element comparison
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = 1; // Mark that a swap occurred
            }
        }
        
        // If no two elements were swapped in the inner loop, array is sorted
        if (swapped == 0) {
            break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(data) / sizeof(data[0]);
    
    printf("Unsorted Array:\n");
    printArray(data, size);
    
    bubbleSort(data, size);
    
    printf("Sorted Array in Ascending Order:\n");
    printArray(data, size);
    
    return 0;
}