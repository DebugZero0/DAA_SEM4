#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, amount;
    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);
    int coins[n];
    printf("Enter the coin denominations:\n");
    for(int i = 0; i < n; i++) {
        printf("Coin %d: ", i + 1);
        scanf("%d", &coins[i]);
    }
    printf("Enter the amount to make change for: ");
    scanf("%d", &amount);

    // Sort coins in descending order (bubble sort)
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(coins[j] < coins[j + 1]) {
                int temp = coins[j];
                coins[j] = coins[j + 1];
                coins[j + 1] = temp;
            }
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        while(amount >= coins[i]) { // As repetition of coins is allowed, we can use the same coin multiple times
            amount -= coins[i];
            count++;
        }
    }

    if(amount == 0) {
        printf("Minimum number of coins required: %d\n", count);
    } else {
        printf("Change cannot be made with the given denominations.\n");
    }
    
    return 0;
}

// Time Complexity: O(n^2) due to the bubble sort implementation.
// Space Complexity: O(1) as we are using a constant amount of extra space.