#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int prices[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &prices[i]);

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++) {
        if (prices[i] < minPrice)
            minPrice = prices[i];         // Update minimum price
        else if (prices[i] - minPrice > maxProfit)
            maxProfit = prices[i] - minPrice;  // Update max profit
    }

    printf("%d", maxProfit);

    return 0;
}
