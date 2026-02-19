#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < n; i++) {
        if (currentSum < 0)
            currentSum = nums[i];
        else
            currentSum += nums[i];

        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    printf("%d", maxSum);
    return 0;
}
