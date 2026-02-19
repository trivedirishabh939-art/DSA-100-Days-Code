#include <stdio.h>

// Function to reverse a subarray from index start to end
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, k;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    scanf("%d", &k);

    k = k % n; // In case k > n

    // Step 1: Reverse the whole array
    reverse(nums, 0, n - 1);

    // Step 2: Reverse first k elements
    reverse(nums, 0, k - 1);

    // Step 3: Reverse remaining elements
    reverse(nums, k, n - 1);

    // Print rotated array
    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}
