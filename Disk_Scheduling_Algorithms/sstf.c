#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, totalMovement = 0, head, min, diff, pos;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int request[n], serviced[n];
    printf("Enter the disk request queue:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
        serviced[i] = 0;
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\nSSTF Disk Scheduling:\n");
    printf("Head movements:\n");

    for (i = 0; i < n; i++)
    {
        min = 9999;
        pos = -1;

        for (j = 0; j < n; j++)
        {
            if (!serviced[j])
            {
                diff = abs(request[j] - head);
                if (diff < min)
                {
                    min = diff;
                    pos = j;
                }
            }
        }

        printf("Head moves from %d to %d, distance = %d\n", head, request[pos], min);
        totalMovement += min;
        head = request[pos];
        serviced[pos] = 1;
    }

    printf("\nTotal Head Movement = %d\n", totalMovement);

    return 0;
}
