#include <stdio.h>

int main()
{
    int n, i, j;
    int arrival[100], burst[100], waiting[100], turnaround[100], completion[100], process[100], startTime[100], response[100];
    int totalWaiting = 0, totalTurnaround = 0, totalResponse = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for P%d: ", i + 1);
        scanf("%d%d", &arrival[i], &burst[i]);
        process[i] = i + 1;
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arrival[j] < arrival[i])
            {

                int temp = arrival[i];
                arrival[i] = arrival[j];
                arrival[j] = temp;

                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;

                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    int currentTime = 0;
    for (i = 0; i < n; i++)
    {
        if (currentTime < arrival[i])
        {
            currentTime = arrival[i];
        }

        startTime[i] = currentTime;
        currentTime += burst[i];
        completion[i] = currentTime;
        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];
        response[i] = startTime[i] - arrival[i];

        totalWaiting += waiting[i];
        totalTurnaround += turnaround[i];
        totalResponse += response[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\tRT\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", process[i], arrival[i], burst[i], completion[i], waiting[i], turnaround[i], response[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", (float)totalWaiting / n);
    printf("Average Turnaround Time = %.2f\n", (float)totalTurnaround / n);
    printf("Average Response Time = %.2f\n", (float)totalResponse / n);

    return 0;
}
