#include <stdio.h>

void merge(int nums1[], int m, int nums2[], int n) {
    int i = m - 1;   // Last index of initial nums1 elements
    int j = n - 1;   // Last index of nums2
    int k = m + n - 1; // Last index of merged array

    // Merge from the end
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Copy remaining elements of nums2, if any
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    int m, n;
    scanf("%d", &m);
    int nums1[m + 100]; // allocate extra space for n elements
    for (int i = 0; i < m; i++)
        scanf("%d", &nums1[i]);

    scanf("%d", &n);
    int nums2[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums2[i]);

    // Fill extra space in nums1 with 0 (optional)
    for (int i = m; i < m + n; i++)
        nums1[i] = 0;

    merge(nums1, m, nums2, n);

    // Print merged array
    for (int i = 0; i < m + n; i++)
        printf("%d ", nums1[i]);

    return 0;
}
