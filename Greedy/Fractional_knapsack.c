#include<stdio.h>
#include<stdlib.h>

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    float value[n], weight[n], ratio[n];
    for(int i = 0; i < n; i++){
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%f %f", &value[i], &weight[i]);
        ratio[i] = value[i] / weight[i];
    }

    // Sort items by ratio in descending order (bubble sort)
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(ratio[j] < ratio[j + 1]){
                // Swap ratio
                swap(&ratio[j], &ratio[j + 1]);

                // Swap value
                swap(&value[j], &value[j + 1]);

                // Swap weight
                swap(&weight[j], &weight[j + 1]);
            }
        }
    }

    float totalValue = 0.0;
    for(int i = 0; i < n; i++){
        if(weight[i] <= capacity){
            totalValue += value[i];
            capacity -= weight[i];
        } else {
            totalValue += ratio[i] * capacity; // optimal 
            break;
        }
    }
    printf("Total value in the knapsack: %.2f\n", totalValue);
    return 0;
}

// Time Complexity: O(n^2) due to the bubble sort implementation.
// Space Complexity: O(n) for storing value, weight, and ratio arrays.