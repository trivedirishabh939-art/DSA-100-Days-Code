#include <stdio.h>
#include <stdbool.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int matrix[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &matrix[i][j]);

    bool isToeplitz = true;

    for (int i = 0; i < r - 1; i++) {
        for (int j = 0; j < c - 1; j++) {
            if (matrix[i][j] != matrix[i + 1][j + 1]) {
                isToeplitz = false;
                break;
            }
        }
        if (!isToeplitz) break;
    }

    if (isToeplitz)
        printf("true");
    else
        printf("false");

    return 0;
}
