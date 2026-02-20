#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: "); // Visual cue
    if (scanf("%d", &n) != 1) return 1;

    if (n > 1000) {
        printf("N is too large for the fixed array!\n");
        return 1;
    }

    int arr[1000];
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int count = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum == 0)
                count++;
        }
    }

    printf("Result: %d\n", count);
    return 0;
}