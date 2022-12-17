#include <stdio.h>
int dequeue(int front, int back, int n)
{
    if (front == back || front == -1)
        front = -1;
    else
        front = (front + 1) % n;
    return front;
}
int enqueue(int queue[], int v, int front, int back, int n)
{
    int i;
    if (front != -1)
    {
        for (i = front; i != back; i = (i + 1) % n)
            if (v == queue[i])
                return back;
        if (queue[back] == v)
            return back;
    }
    if ((back + 1) % n != front)
    {
        back = (back + 1) % n;
        queue[back] = v;
    }
    return back;
}
int main()
{
    int queue[50];
    int front = -1, tail = -1, v, n, i, j, qs = 50;
    int pid[10], at[10], bt[10], bt2[10], ct[10], tat[10], wt[10], vis[10] = {0};
    int noOfZeroes = 0, tq, t = 0, temp, totaltat = 0, totalwt = 0;
    printf("Input no of Process :");
    scanf("%d", &n);
    printf("Input Quantum time :");
    scanf("%d", &tq);
    printf("AT BT\n");
    for (i = 0; i < n; i++)
        pid[i] = i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
    }
    for (i = 0; i < n; i++)
        bt2[i] = bt[i];

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    t += at[0];
    tail = enqueue(queue, 0, front, tail, qs);
    if (tail == 0 && front == -1)
        front = 0;

    while (noOfZeroes != n)
    {
        if (front != -1)
        {
            j = queue[front];
            if (bt[j] >= tq)
            {
                t += tq;
                bt[j] -= tq;
            }
            else
            {
                t += bt[j];
                bt[j] = 0;
            }
            if (bt[j] == 0)
            {
                ct[j] = t;
                vis[j] = 1;
                noOfZeroes++;
            }
            front = dequeue(front, tail, qs);
            if (front == -1)
                tail = -1;
            for (i = 0; i < n; i++)
            {
                if (i == j)
                    continue;
                if (vis[i] == 0 && at[i] <= t && bt[i] != 0)
                {
                    tail = enqueue(queue, i, front, tail, qs);
                    if (tail == 0 && front == -1)
                        front = 0;
                }
            }
            if (bt[j] != 0)
            {
                tail = enqueue(queue, j, front, tail, qs);
                if (tail == 0 && front == -1)
                    front = 0;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        totaltat += tat[i];
    }

    for (i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt2[i];
        totalwt += wt[i];
    }

    printf("\n%5s%5s%5s%5s%5s%5s\n", "pid", "at", "bt", "ct", "tat", "wt");
    for (i = 0; i < n; i++)
    {
        printf("%5d%5d%5d%5d%5d%5d\n", i, at[pid[i]], bt2[pid[i]], ct[pid[i]], tat[pid[i]], wt[pid[i]]);
    }
    printf("Avarage Turn Around Time : %0.3lf\n", totaltat * 1.0 / n);
    printf("Avarage Waiting Time : %0.3lf\n", totalwt * 1.0 / n);

    return 0;
}