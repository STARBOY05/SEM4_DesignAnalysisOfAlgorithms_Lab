#include <stdio.h>
#define MAX 20

char X[MAX] = "STONE", Y[MAX] = "LONGEST";
int m = 5, n = 7, result[MAX][MAX] = {0}, i, j;

void getLCS(int i, int j)
{
    if (i <= 0 || j <= 0)
        return;
    else if (result[i][j] != result[i - 1][j] && result[i][j] != result[i][j - 1])
    {
        getLCS(i - 1, j - 1);
        printf("%c ", X[i - 1]);
    }
    else if (result[i][j] == result[i - 1][j])
        getLCS(i - 1, j);
    else
        getLCS(i, j - 1);
}

int main()
{
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
                result[i][j] = 1 + result[i - 1][j - 1];
            else
            {
                if (result[i - 1][j] >= result[i][j - 1])
                    result[i][j] = result[i - 1][j];
                else
                    result[i][j] = result[i][j - 1];
            }
        }
    }
    // Display Y in horizontal
    for (j = 0; j <= n; j++)
        printf("\t%c", Y[j-1]);
    printf("\n");
    for (i = 0; i <= m; i++)
    {
        // Display X in vertical
        printf("%c", X[i - 1]);
        for (j = 0; j <= n; j++)
            printf("\t%d", result[i][j]);
        printf("\n");
    }
    printf("\nLeast Common Subsequence: ");
    getLCS(m, n);
    return 0;
}