#include <stdio.h>
#include <string.h>

void reverseString(char s[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        // Swap characters
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char s[n + 1]; // +1 for null terminator
    for (int i = 0; i < n; i++) {
        scanf(" %c", &s[i]); // space before %c to ignore whitespace
    }
    s[n] = '\0'; // null terminate (optional for printing)

    reverseString(s, n);

    for (int i = 0; i < n; i++)
        printf("%c", s[i]);

    return 0;
}
