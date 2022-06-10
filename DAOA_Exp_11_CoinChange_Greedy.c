#include <stdio.h>
#define MAX 10
void main()
{
    int i, j, n=7, temp, value=75, coins[MAX]={1, 2, 5, 10, 20, 50, 100}, result[MAX];
    // printf("Enter the number of coins: ");
    // scanf("%d", &n);
    // printf("Enter the coins: ");
    // for (i = 0; i < n; i++)
    //     scanf("%d", &coins[i]);
    printf("Coin Denomination: ");
    for (i = 0; i < n; i++)
        printf(" %d", coins[i]);
    // printf("\nEnter the amount for exchange: ");
    // scanf("%d", &value);
    for (i=0; i<n-1; i++)
    {
        for (j=0; j<n-i-1; j++)
        {
            if (coins[j] < coins[j + 1])
            {
                temp = coins[j];
                coins[j] = coins[j + 1];
                coins[j + 1] = temp;
            }
        }
    }
    printf("\nSorting coins in descending order\n");
    for (i = 0; i < n; i++)
        printf(" %d", coins[i]);
    printf("\nRequired Coins: ");
    for(i=0;i<n;i++)
    {
        while(coins[i] <= value)
        {
            printf("%d ", coins[i]);
            value-=coins[i];
            if(value==0)    break;
        }
    }
}