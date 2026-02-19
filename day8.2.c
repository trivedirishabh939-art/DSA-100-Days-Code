#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);

    bool isPowerOfTwo = (n > 0) && ((n & (n - 1)) == 0);

    if (isPowerOfTwo)
        printf("true");
    else
        printf("false");

    return 0;
}
