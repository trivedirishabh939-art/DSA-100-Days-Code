#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n - 1];
    int sum = 0;

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // Total sum of 1 to n = n*(n+1)/2
    int total = n * (n + 1) / 2;

    int missing = total - sum;
    printf("%d", missing);

    return 0;
}
