#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    int start[n], finish[n];
    printf("Enter the start and finish times of the activities:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Activity %d : ", i + 1);
        scanf("%d %d", &start[i], &finish[i]);
    }

    // Sort activities based on finish times (bubble sort)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (finish[j] > finish[j + 1])
            {
                // Swap finish times
                swap(&finish[j], &finish[j + 1]);
                // Swap corresponding start times
                swap(&start[j], &start[j + 1]);
            }
        }
    }
    int last = 0;

    printf("Activity (Start: %d, Finish: %d)\n", start[0], finish[0]);
    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if (start[i] >= finish[last]) 
        {
            printf("Activity (Start: %d, Finish: %d)\n", start[i], finish[i]);
            count++;
            last = i; // Update last selected activity(index) to the current one
        }
    }
    printf("Total selected activities: %d\n", count);
    return 0;
}

// Time Complexity: O(n^2) due to the bubble sort implementation.
// Space Complexity: O(1) as we are using a constant amount of extra space.