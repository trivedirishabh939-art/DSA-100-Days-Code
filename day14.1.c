#include <stdio.h>

int main() {
    int n;

    // Input size of matrix
    scanf("%d", &n);

    int a[n][n];

    // Input matrix elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int identity = 1;

    // Check identity matrix condition
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j) {
                if (a[i][j] != 1) {
                    identity = 0;
                    break;
                }
            } else {
                if (a[i][j] != 0) {
                    identity = 0;
                    break;
                }
            }
        }
        if (!identity)
            break;
    }

    // Output result
    if (identity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
