#include <stdio.h>
#include <stdlib.h> //for the abs function

int main()
{
    int n, i, totalMovement = 0, head;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int request[n];
    printf("Enter the disk request queue:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\nFCFS Disk Scheduling:\n");
    printf("Head movements:\n");

    for (i = 0; i < n; i++)
    {
        printf("Head moves from %d to %d, ", head, request[i]);
        printf("distance = %d\n", abs(request[i] - head));
        totalMovement += abs(request[i] - head);
        head = request[i];
    }

    printf("\nTotal Head Movement = %d\n", totalMovement);

    return 0;
}
