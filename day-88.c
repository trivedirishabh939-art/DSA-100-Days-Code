#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place k cows with at least minDist
int canPlace(int stalls[], int n, int k, int minDist) {
    int count = 1;  // first cow placed
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= minDist) {
            count++;
            lastPos = stalls[i];
        }
        if (count == k) return 1;
    }
    return 0;
}

int aggressiveCows(int stalls[], int n, int k) {
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlace(stalls, n, k, mid)) {
            result = mid;      // possible answer
            low = mid + 1;     // try bigger distance
        } else {
            high = mid - 1;    // reduce distance
        }
    }
    return result;
}

// Example usage
int main() {
    int stalls[] = {1, 2, 4, 8, 9};
    int n = 5;
    int k = 3;

    printf("Maximum minimum distance: %d\n", aggressiveCows(stalls, n, k));
    return 0;
}