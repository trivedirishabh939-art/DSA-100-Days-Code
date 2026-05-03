#include <stdio.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* ------------------ LOMUTO PARTITION ------------------ */

// Lomuto partition
int lomutoPartition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort using Lomuto
void quickSortLomuto(int arr[], int low, int high) {
    if (low < high) {
        int pi = lomutoPartition(arr, low, high);

        quickSortLomuto(arr, low, pi - 1);
        quickSortLomuto(arr, pi + 1, high);
    }
}

/* ------------------ HOARE PARTITION ------------------ */

// Hoare partition
int hoarePartition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(&arr[i], &arr[j]);
    }
}

// Quick Sort using Hoare
void quickSortHoare(int arr[], int low, int high) {
    if (low < high) {
        int pi = hoarePartition(arr, low, high);

        quickSortHoare(arr, low, pi);
        quickSortHoare(arr, pi + 1, high);
    }
}

/* ------------------ UTILITY ------------------ */

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Copy array
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

/* ------------------ MAIN ------------------ */

int main() {
    int original[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(original) / sizeof(original[0]);

    int arr1[n], arr2[n];

    // Copy original array
    copyArray(original, arr1, n);
    copyArray(original, arr2, n);

    // Lomuto Sort
    quickSortLomuto(arr1, 0, n - 1);
    printf("Sorted using Lomuto: ");
    printArray(arr1, n);

    // Hoare Sort
    quickSortHoare(arr2, 0, n - 1);
    printf("Sorted using Hoare: ");
    printArray(arr2, n);

    return 0;
}