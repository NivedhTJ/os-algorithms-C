#include <stdio.h>

int main()
{
    int n, i, completed = 0, currentTime = 0;
    int arrival[100], burst[100], waiting[100], turnaround[100], completion[100], process[100], startTime[100], response[100], done[100] = {0};
    int totalWaiting = 0, totalTurnaround = 0, totalResponse = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for P%d: ", i + 1);
        scanf("%d%d", &arrival[i], &burst[i]);
        process[i] = i + 1;
    }

    while (completed < n)
    {
        int idx = -1, minBurst = 999;

        for (i = 0; i < n; i++)
        {
            if (!done[i] && arrival[i] <= currentTime && burst[i] < minBurst)
            {
                minBurst = burst[i];
                idx = i;
            }
        }

        if (idx != -1)
        {
            startTime[idx] = currentTime;
            currentTime += burst[idx];
            completion[idx] = currentTime;
            turnaround[idx] = completion[idx] - arrival[idx];
            waiting[idx] = turnaround[idx] - burst[idx];
            response[idx] = startTime[idx] - arrival[idx];
            done[idx] = 1;
            completed++;

            totalWaiting += waiting[idx];
            totalTurnaround += turnaround[idx];
            totalResponse += response[idx];
        }
        else
        {
            currentTime++;
        }
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
