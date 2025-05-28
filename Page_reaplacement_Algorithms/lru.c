#include <stdio.h>

int findLRU(int time[], int n)
{
    int i, min = time[0], pos = 0;
    for (i = 1; i < n; i++)
    {
        if (time[i] < min)
        {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main()
{
    int n, frames, i, j, k, pageFaults = 0, timeCount = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the page reference string:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    int frame[frames], time[frames];
    for (i = 0; i < frames; i++)
    {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("\nPage replacement process:\n");

    for (i = 0; i < n; i++)
    {
        int found = 0;

        for (j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
            {
                found = 1;
                time[j] = ++timeCount;
                break;
            }
        }

        if (!found)
        {
            int pos = -1;

            for (j = 0; j < frames; j++)
            {
                if (frame[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            if (pos == -1)
            {
                pos = findLRU(time, frames);
            }

            frame[pos] = pages[i];
            time[pos] = ++timeCount;
            pageFaults++;

            for (k = 0; k < frames; k++)
            {
                if (frame[k] != -1)
                    printf("%d ", frame[k]);
                else
                    printf("- ");
            }
            printf(" <-- Page Fault\n");
        }
        else
        {

            for (k = 0; k < frames; k++)
            {
                if (frame[k] != -1)
                    printf("%d ", frame[k]);
                else
                    printf("- ");
            }
            printf("\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}
