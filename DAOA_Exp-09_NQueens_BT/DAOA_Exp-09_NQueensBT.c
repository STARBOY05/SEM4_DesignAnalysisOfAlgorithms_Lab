#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int board[MAX], count = 1;
// Display solution table
void display(int n)
{
    int i, j;
    printf("\nSolution %d:\n", count++);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (board[i] == j)
                printf("%d ", board[i]);
        }
    }
    // for (i = 1; i <= n; i++)
    //     printf("\t%d", i);
    // for (i = 1; i <= n; i++)
    // {
    //     printf("\n%d", i);
    //     for (j = 1; j <= n; j++)
    //     {
    //         if (board[i] == j)
    //             printf("\tQ%d", i);
    //         else
    //             printf("\t*");
    //     }
    // }
    printf("\n");
}

int place(int row, int col)
{
    int i;
    // Checking the columns and diagonals of current Queen if problem return 0 else 1
    for (i = 1; i <= row - 1; i++)
    {
        //  Column condition        Diagonal Condition
        if ((board[i] == col) || (abs(board[i] - col) == abs(i - row)))
            return 0;
    }
    return 1;
}

// Positioning the Queen
void queen(int row, int n)
{
    int col;
    // row is nothing but queen as all queens should be placed in different rows
    for (col = 1; col <= n; col++)
    {
        if (place(row, col))
        {
            board[row] = col; // no conflicts so place queen
            if (row == n)     // when all queens are placed
                display(n);   // print the board
            else              // else try queen for next position
                queen(row + 1, n);
        }
    }
}

int main()
{
    int n, i, j;
    printf(" N-Queens Problem Using Backtracking -");
    printf("\n Enter number of Queens:");
    scanf("%d", &n);
    queen(1, n);
    return 0;
}
