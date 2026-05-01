#include <stdio.h>

// Function to check if possible with given maxTime
int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime)
            return 0;

        if (currSum + boards[i] <= maxTime) {
            currSum += boards[i];
        } else {
            painters++;
            currSum = boards[i];

            if (painters > k)
                return 0;
        }
    }
    return 1;
}

// Function to find minimum time
int minTime(int boards[], int n, int k) {
    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > low)
            low = boards[i];   // max element
        high += boards[i];     // total sum
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;   // try smaller
        } else {
            low = mid + 1;    // increase limit
        }
    }

    return ans;
}

// Driver Code
int main() {
    int boards[] = {10, 20, 30, 40};
    int n = 4;
    int k = 2;

    printf("Minimum time: %d\n", minTime(boards, n, k));

    return 0;
}