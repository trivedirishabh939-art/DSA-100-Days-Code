#include <stdio.h>

void moveZeroes(int nums[], int n) {
    int k = 0; // position to place next non-zero

    // Move non-zero elements forward
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[k] = nums[i];
            k++;
        }
    }

    // Fill remaining positions with zeros
    for (int i = k; i < n; i++)
        nums[i] = 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    moveZeroes(nums, n);

    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}
