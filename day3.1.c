#include <stdio.h>

int main() {
    int n, k;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key
    scanf("%d", &k);

    int comparisons = 0;
    int found = -1;

    // Linear search
    for (int i = 0; i < n; i++) {
        comparisons++;

        if (arr[i] == k) {
            found = i;
            break;
        }
    }

    // Output result
    if (found != -1)
        printf("Found at index %d\n", found);
    else
        printf("Not Found\n");

    printf("Comparisons = %d\n", comparisons);

    return 0;
}
