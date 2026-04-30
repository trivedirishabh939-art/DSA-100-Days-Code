#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages) {
            return 0; // not possible
        }

        if (pages + arr[i] <= maxPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];

            if (students > m) {
                return 0;
            }
        }
    }
    return 1;
}

int allocateBooks(int arr[], int n, int m) {
    if (n < m) return -1;

    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int low = max, high = sum, result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1; // try smaller
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int arr[] = {12, 34, 67, 90};
    int n = 4;
    int m = 2;

    printf("Minimum maximum pages = %d\n", allocateBooks(arr, n, m));
    return 0;
}