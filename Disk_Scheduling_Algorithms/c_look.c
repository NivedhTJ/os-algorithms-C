#include <stdio.h>
#include <stdlib.h> //for abs function

int main()
{

    int n, i, j, totalMovement = 0, head, temp;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int size = n + 1; //size increased by one to store the head

    int request[size];
    printf("Enter the disk request queue:\n");
    for (i = 0; i < n; i++) //n requests are taken as input 
    {
        scanf("%d", &request[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);
    request[size - 1] = head; // head stored to the last index of the array

    for (i = 0; i < size - 1; i++) // bubble sort the request along with the head
    {
        for (j = i + 1; j < size; j++)
        {
            if (request[i] > request[j])
            {
                temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }

    printf("\nC Look Disk Scheduling:\n");

    int start = 0;
    for (i = 0; i < n; i++) //sort through the array to find the head
    {
        if (request[i] == head)
        {
            start = i; // found the starting index as i
            break;
        }
    }

    printf("Head movements:\n");

    for (i = start + 1; i < size; i++) // starts servicing requests to the right side of head
    {
        printf("Head moves from %d to %d, distance = %d\n", head, request[i], abs(request[i] - head));
        totalMovement += abs(request[i] - head);
        head = request[i];
    }

    if (start > 0) // jumps to leftmost side 
    {
        printf("Head jumps from %d to %d, distance = %d\n", head, request[0], abs(head - request[0]));
        totalMovement += abs(head - request[0]);
        head = request[0];
    }

    for (i = 0; i < start; i++) // starts servicing from leftmost side to the initial head position
    {
        printf("Head moves from %d to %d, distance = %d\n", head, request[i], abs(request[i] - head));
        totalMovement += abs(request[i] - head);
        head = request[i];
    }

    printf("\nTotal Head Movement = %d\n", totalMovement);

    return 0;
}
