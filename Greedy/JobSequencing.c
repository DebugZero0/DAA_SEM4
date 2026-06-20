#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n, i, j;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    int profit[n], deadline[n];

    printf("Enter profit and deadline for each job:\n");
    for(i = 0; i < n; i++) {
        printf("Job %d : ", i + 1);
        scanf("%d %d", &profit[i], &deadline[i]);
    }

    // Sort jobs by profit (descending)
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(profit[i] < profit[j]) {
                swap(&profit[i], &profit[j]);

                swap(&deadline[i], &deadline[j]);
            }
        }
    }

    // Find maximum deadline
    int maxDeadline = 0;
    for(i = 0; i < n; i++) {
        if(deadline[i] > maxDeadline)
            maxDeadline = deadline[i];
    }

    int slot[maxDeadline + 1];

    for(i = 0; i <= maxDeadline; i++)
        slot[i] = -1;

    int totalProfit = 0;

    printf("\nSelected Jobs:\n");

    for(i = 0; i < n; i++) {
        // Find a free slot for this job (starting from its deadline) and going backwards because if the deadline is 3, we can schedule it in slot 3, 2, or 1 if 3 is occupied.
        for(j = deadline[i]; j > 0; j--) { 
            if(slot[j] == -1) { // If slot is free
                slot[j] = i;
                totalProfit += profit[i];

                printf("Job with Profit %d at Slot %d\n",
                       profit[i], j);
                break;// Break the loop once a slot is found
            }
        }
    }

    printf("\nMaximum Profit = %d\n", totalProfit);

    return 0;
}

// Time Complexity: O(n^2) due to the nested loops for sorting and job selection
// Space Complexity: O(maxDeadline) for the slot array