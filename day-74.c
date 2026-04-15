#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int n;
    printf("Enter number of votes: ");
    scanf("%d", &n);

    char votes[MAX][MAX];

    printf("Enter candidate names:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    // Sort the names lexicographically
    qsort(votes, n, sizeof(votes[0]), compare);

    char winner[MAX];
    int maxVotes = 1, currentVotes = 1;

    strcpy(winner, votes[0]);

    for (int i = 1; i < n; i++) {
        if (strcmp(votes[i], votes[i - 1]) == 0) {
            currentVotes++;
        } else {
            currentVotes = 1;
        }

        // Update winner
        if (currentVotes > maxVotes) {
            maxVotes = currentVotes;
            strcpy(winner, votes[i]);
        }
    }

    printf("Winner: %s\nVotes: %d\n", winner, maxVotes);

    return 0;
}