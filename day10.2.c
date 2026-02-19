#include <stdio.h>

int main() {
    int n1, n2;
    scanf("%d", &n1);
    int nums1[n1];
    for (int i = 0; i < n1; i++)
        scanf("%d", &nums1[i]);

    scanf("%d", &n2);
    int nums2[n2];
    for (int i = 0; i < n2; i++)
        scanf("%d", &nums2[i]);

    int result[n1 < n2 ? n1 : n2]; // max possible size
    int k = 0;

    // Create a frequency array for nums1
    int freq1[1001] = {0}; // assuming numbers <= 1000
    for (int i = 0; i < n1; i++)
        freq1[nums1[i]]++;

    // Check nums2 against nums1's frequency
    for (int i = 0; i < n2; i++) {
        if (freq1[nums2[i]] > 0) {
            result[k++] = nums2[i];
            freq1[nums2[i]]--;
        }
    }

    // Print result
    for (int i = 0; i < k; i++)
        printf("%d ", result[i]);

    return 0;
}
