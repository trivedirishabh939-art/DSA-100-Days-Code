#include <stdio.h>
#include <stdbool.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    bool firstRowZero = false, firstColZero = false;

    // Check if first row has a zero
    for (int j = 0; j < n; j++)
        if (matrix[0][j] == 0) firstRowZero = true;

    // Check if first column has a zero
    for (int i = 0; i < m; i++)
        if (matrix[i][0] == 0) firstColZero = true;

    // Use first row and column as markers
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set cells to zero according to markers
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    // Set first row to zero if needed
    if (firstRowZero)
        for (int j = 0; j < n; j++)
            matrix[0][j] = 0;

    // Set first column to zero if needed
    if (firstColZero)
        for (int i = 0; i < m; i++)
            matrix[i][0] = 0;

    // Print result
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    return 0;
}
