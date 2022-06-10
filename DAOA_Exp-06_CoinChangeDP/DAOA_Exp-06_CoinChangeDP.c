// Coin Change Problem
#include <stdio.h>
#define MAX 20

int i, j, coins[MAX], result[MAX][MAX] = {0}, reqd_coins[MAX] = {0}, num, amount, temp = 0, temp1 = 0, temp2 = 0;
// Sorting function to sort the coins in ascending order before use
void sort()
{
    for (i = 1; i <= num; i++)
    {
        for (j = 1; j <= num - i; j++)
        {
            if (coins[j] > coins[j + 1])
            {
                temp = coins[j];
                coins[j] = coins[j + 1];
                coins[j + 1] = temp;
            }
        }
    }
}
// Get the required input
void getInput()
{
    // Enter the number of coins
    printf("Enter the number of denominations: ");
    scanf("%d", &num);
    for (i = 1; i <= num; i++)
    {
        printf("Enter coin: ");
        scanf("%d", &coins[i]);
    }
    // Sort the coins in ascending order
    sort();
    printf("Coin Denomination: ");
    for (i = 1; i <= num; i++)
        printf("%d ", coins[i]);
    // Ask for change amount
    printf("\nEnter the amount for change: ");
    scanf("%d", &amount);
}

void coinChange()
{
    // Outer loop for number of coins
    for (i = 0; i <= num; i++)
    {
        // Inner loop for the amount
        for (j = 0; j <= amount; j++)
        {
            // either i = 0 or j = 0 --> result = 0
            if (i == 0 || j == 0)
                result[i][j] = 0;
            // Check second formula
            else if (j < coins[i])
                result[i][j] = result[i - 1][j];
            // Check first formula
            else if ((i == j) || (i == 1))
                result[i][j] = 1 + result[i][j - coins[i]];
            // Otherwise
            else
            {
                temp1 = result[i - 1][j];
                temp2 = 1 + result[i][j - coins[i]];
                if (temp1 < temp2)
                    result[i][j] = temp1;
                else
                    result[i][j] = temp2;
            }
        }
    }
}

void display()
{
    printf("\n");
    printf("\tj-> ");
    for (j = 0; j <= amount; j++)
        printf("%d ", j);
    printf("\n");
    for (i = 0; i <= num; i++)
    {
        printf("di=%d\ti=%d ", coins[i], i);
        for (j = 0; j <= amount; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }
    printf("\nNumber of coins required are %d", result[num][amount]);
    temp = num;
    i=0;
    while (amount != 0)
    {
        if (result[num][amount] != result[num - 1][amount])
        {
            reqd_coins[i] = coins[num];
            amount -= coins[num];
            i++;
        }
        else    num--;
    }
    printf("\nCoins are { ");
    for (i = 0; i <= temp; i++)
    {
        if (reqd_coins[i] != 0)
            printf("%d ", reqd_coins[i]);
    }
    printf("}");
}

void main()
{
    getInput();
    coinChange();
    display();
}