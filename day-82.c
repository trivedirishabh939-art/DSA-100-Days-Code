#include <stdio.h>

// Lower Bound: first index where arr[i] >= x
int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;  // default if not found

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1; // search left
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// Upper Bound: first index where arr[i] > x
int upperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;  // default if not found

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1; // search left
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("Lower Bound index: %d\n", lb);
    printf("Upper Bound index: %d\n", ub);

    return 0;
}