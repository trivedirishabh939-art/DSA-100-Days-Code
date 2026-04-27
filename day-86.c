#include <stdio.h>

int integerSqrt(int n) {
    int low = 0, high = n, mid;
    int ans = 0;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if ((long long)mid * mid == n)
            return mid;
        else if ((long long)mid * mid < n) {
            ans = mid;       // possible answer
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n = 17;
    printf("Integer square root of %d is %d\n", n, integerSqrt(n));
    return 0;
}