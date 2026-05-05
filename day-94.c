#include <stdio.h>
#include <stdlib.h>

// Function for Counting Sort
void countingSort(int arr[], int n) {
    int i;

    // Step 1: Find maximum element
    int max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Step 2: Create frequency array
    int *count = (int *)calloc(max + 1, sizeof(int));

    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Step 3: Compute prefix sums (cumulative count)
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Step 4: Build output array
    int *output = (int *)malloc(n * sizeof(int));

    // Traverse from end to maintain stability
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy sorted elements back to original array
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Free memory
    free(count);
    free(output);
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code
int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    countingSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}