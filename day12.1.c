#include <stdio.h>

int main() {
    int m, n;

    // Input rows and columns
    scanf("%d %d", &m, &n);

    int a[m][n];

    // Input matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Matrix must be square
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    int symmetric = 1;

    // Check symmetry
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if (!symmetric)
            break;
    }

    // Output result
    if (symmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
