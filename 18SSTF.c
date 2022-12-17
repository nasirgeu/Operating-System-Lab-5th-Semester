#include <stdio.h>
#include <stdlib.h>
int main()
{
    int ReadyQueue[100], i, n, TotalHeadMoment = 0, initial, count = 0;
    printf("Input Initial R/W header Position :");
    scanf("%d", &initial);
    printf("Input size :");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &ReadyQueue[i]);

    while (count != n)
    {
        int min = 1000, diff, index;
        for (i = 0; i < n; i++)
        {
            diff = abs(ReadyQueue[i] - initial);
            if (min > diff)
            {
                min = diff;
                index = i;
            }
        }
        TotalHeadMoment = TotalHeadMoment + min;
        initial = ReadyQueue[index];
        ReadyQueue[index] = 1000;
        count++;
    }
    printf("Total head movement is %d", TotalHeadMoment);
}