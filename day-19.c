#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); // Simplified comparison
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1; // Check if input is valid

    if (n < 2) {
        printf("Need at least 2 numbers\n");
        return 0;
    }

    int *arr = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int minSum = INT_MAX;
    int bestL = 0, bestR = n - 1;

    while(left < right) {
        int sum = arr[left] + arr[right];

        // Use labs() or manual check if sum could exceed INT limits
        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            bestL = left;
            bestR = right;
        }

        if (sum < 0) 
            left++;
        else if (sum > 0) 
            right--;
        else 
            break; // Found a perfect zero sum, can stop early
    }

    printf("Result: %d %d\n", arr[bestL], arr[bestR]);

    free(arr);
    return 0;
}