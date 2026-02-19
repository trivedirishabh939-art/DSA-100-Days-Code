#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    // Input string
    scanf("%s", str);

    int left = 0;
    int right = strlen(str) - 1;

    // Reverse using two-pointer approach
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }

    // Output reversed string
    printf("%s", str);

    return 0;
}
