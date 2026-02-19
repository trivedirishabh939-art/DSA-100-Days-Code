#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    
    // Input string
    scanf("%s", s);

    int left = 0;
    int right = strlen(s) - 1;
    int isPalindrome = 1;

    // Two-pointer comparison
    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    // Output result
    if (isPalindrome)
        printf("YES");
    else
        printf("NO");

    return 0;
}
