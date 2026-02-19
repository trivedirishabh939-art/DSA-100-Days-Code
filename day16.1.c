#include <stdio.h>

int main() {
    int n;

    // Input size
    scanf("%d", &n);

    int arr[n];
    int visited[n];

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0;
    }

    // Count frequency
    for (int i = 0; i < n; i++) {

        if (visited[i])
            continue;

        int count = 1;

        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;
            }
        }

        printf("%d:%d ", arr[i], count);
    }

    return 0;
}
