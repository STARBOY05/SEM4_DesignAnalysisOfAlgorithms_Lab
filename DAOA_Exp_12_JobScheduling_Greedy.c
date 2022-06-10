// Knapsack Problem (Greedy Algorithm)
#include <stdio.h>
#define MAX 10

typedef struct job
{
    int num, deadline, profit;
} job;

typedef struct job_list
{
    job data[MAX];
    int n;
} job_list;

job_list J1;
int dmax = 0;

void display()
{
    int i;
    printf("\n");
    printf("Jobs\tDeadline\tProfits");
    printf("\n");
    for (i = 0; i < J1.n; i++)
    {
        printf("%d\t", J1.data[i].num);
        printf("%d\t\t", J1.data[i].deadline);
        printf("%d", J1.data[i].profit);
        printf("\n");
    }
}
void sort()
{
    int i, j;
    job temp;
    for (i = 0; i < J1.n - 1; i++)
    {
        for (j = 0; j < J1.n - i - 1; j++)
        {
            if (J1.data[j].profit < J1.data[j + 1].profit)
            {
                temp = J1.data[j];
                J1.data[j] = J1.data[j + 1];
                J1.data[j + 1] = temp;
            }
        }
    }
}

int findmaxdeadline()
{
    int i;
    for (i = 0; i < J1.n; i++)
    {
        if (J1.data[i].deadline > dmax)
            dmax = J1.data[i].deadline;
    }
    return dmax;
}
void main()
{
    int n, i, j, k, timeslot[MAX], filledTimeSlot = 0, max_profit=0;
    printf(" Enter the number of jobs: ");
    scanf("%d", &n);
    J1.n = 0;
    for (i = 0; i < n; i++)
    {
        J1.data[i].num = i + 1;
        printf("Enter the deadline and profit for J-%d: ", i + 1);
        scanf("%d %d", &J1.data[J1.n].deadline, &J1.data[J1.n].profit);
        J1.n++;
    }
    display();
    sort();
    printf("\nAfter sorting according to profits\n");
    display();
    dmax = findmaxdeadline();
    printf("Maximum Deadline : %d\n", dmax);
    // free time slots initially set to -1 [-1 denotes EMPTY]
    for (i = 1; i <= dmax; i++)
        timeslot[i] = -1;
    for (i = 0; i < J1.n; i++)
    {
        k = J1.data[i].deadline;
        while (k >= 1)
        {
            if (timeslot[k] == -1)
            {
                timeslot[k] = J1.data[i].num;
                max_profit += J1.data[i].profit;
                // printf("For J%d -> TS-%d\n", J1.data[i].num, k);
                filledTimeSlot++;
                break;
            }
            k--;
        }
        // if all time slots are filled then stop
        if (filledTimeSlot == dmax)
            break;
    }
    // printf("\nGANTT CHART\n");
    printf("\nRequired Jobs: ");
    for (i = 1; i <= dmax; i++)
    {
        // max_profit += J1.data[timeslot[i]].profit;
        printf("J%d", timeslot[i]);
        if (i < dmax)
            printf(" --> ");
    }
    printf("\nMaximum Profit: %d", max_profit);
}