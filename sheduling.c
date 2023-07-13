/*7.Design, develop and implement a C/C++/Java program to simulate the working of
Shortest remaining time and Round Robin (RR) scheduling algorithms. Experiment
with different quantum sizes for RR algorithm.*/

#include <stdio.h>

int main()
{
    int c, n, at[10], bt[10], rt[10], tq, rempro, time, flag = 0, pid , shortest, endtime;
    float wt = 0, tat = 0;

    printf("1.RR\n2.SRTF\n3.Exit\n");
    scanf("%d", &c);

    printf("Enter the no of process:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time: ");
        scanf("%d", &at[i]);
        printf("Enter the burst time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    switch (c)
    {
    case 1:
        printf("Round Robin :");
        printf("Enter the time quantum: ");
        scanf("%d", &tq);
        rempro = n;
        printf("\nProcess time|Turnaround Time|Waiting Time\n");
        for (time = 0, pid = 0; rempro != 0;)
        {
            if (rt[pid] <= tq && rt[pid] > 0)
            {
                time += rt[pid];
                rt[pid] = 0;
                flag = 1;
            }
            else if (rt[pid] > tq)
            {
                rt[pid] -= tq;
                time += tq;
            }
            if (rt[pid] == 0 && flag == 1)
            {
                rempro--;
                printf("P[%d]\t|\t%d\t|\t%d\n", pid + 1, time - at[pid], time - at[pid] - bt[pid]);
                wt += time - at[pid] - bt[pid];
                tat += time - at[pid];
                flag = 0;
            }
            if (pid == n - 1)
            {
                pid = 0;
            }
            else if (at[pid + 1] <= time)
            {
                pid++;
            }
            else
            {
                pid = 0;
            }
        }
        printf("\nAverage waiting time = %f\n", wt * 1.0 / n);
        printf("Average Turnaround time = %f", tat * 1.0 / n);
        break;

    case 2:
        rempro=0;
        printf("\nProcesst|Turnaround Time| Waiting Time\n");
        rt[9] = 9999;
        for(time=0;rempro!=n;time++){
            shortest=9;
            for(int i=0;i<n;i++){
                if(at[i]<=time && rt[i]<rt[shortest] && rt[i]>0){
                    shortest = i;
                }
            }
            rt[shortest]--;
            if(rt[shortest]==0){
                rempro++;
                endtime=time+1;
                printf("\nP[%d]\t|\t%d\t|\t%d", shortest + 1, endtime - at[shortest], endtime - bt[shortest] - at[shortest]);
                printf("\n");
                wt+=endtime - bt[shortest] - at[shortest];
                tat+=endtime - at[shortest];
            }
        }
        printf("\nAverage waiting time = %f\n", wt * 1.0 / n);
        printf("Average Turnaround time = %f", tat * 1.0 / n);
        break;

    case 3:
        exit(0);
    default:
        printf("Invalid\n");
    }

    return 0;
}