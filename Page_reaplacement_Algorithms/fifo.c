#include <stdio.h>

int main()
{
    int n, frames, i, j, k, pageFaults = 0, index = 0;

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

    int frame[frames];
    for (i = 0; i < frames; i++)
    {
        frame[i] = -1;
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
                break;
            }
        }

        if (!found)
        {
            frame[index] = pages[i];
            index = (index + 1) % frames;
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
