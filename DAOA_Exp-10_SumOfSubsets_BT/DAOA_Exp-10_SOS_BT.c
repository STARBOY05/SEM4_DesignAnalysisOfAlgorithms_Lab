#include <stdio.h>
#define MAX 10

int reqd_sum = 10;
int set[MAX] = {1, 2, 3, 4, 5};
int len = 5;

void SOS(int level, int sum, int results[MAX])
{
    int i;
    if (sum == reqd_sum)
    {
        for (i = 0; i < len; i++)
        {
            if (results[i] == 1)
                printf("%d ", set[i]);
        }
        printf("\n");
    }
    else if (sum > reqd_sum || level > len)
        return;
    else
    {
        // select
        results[level] = 1;
        SOS(level + 1, sum + set[level], results);

        // dont select
        results[level] = 0;
        SOS(level + 1, sum, results);
    }
}

int main()
{
    int results[MAX] = {0};
    printf("Numbers forming the required sum are: \n");
    SOS(0, 0, results);
    return 0;
}