#include <stdio.h>

char firstRepeatedChar(char *s) {
    int seen[26] = {0};  // For 'a' to 'z'

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if (seen[index] == 1) {
            return s[i];  // First character whose second occurrence is smallest
        }

        seen[index] = 1;
    }

    return '\0';  // No repeated character
}

int main() {
    char s[100];

    printf("Enter a string: ");
    scanf("%s", s);

    char result = firstRepeatedChar(s);

    if (result != '\0') {
        printf("First repeated character: %c\n", result);
    } else {
        printf("No repeated character found.\n");
    }

    return 0;
}