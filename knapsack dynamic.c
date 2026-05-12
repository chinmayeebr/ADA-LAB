#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], profit[n];

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }

    printf("Enter profits of items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &profit[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    int dp[n + 1][capacity + 1];

    // Initialize table
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (weight[i - 1] <= j)
            {
                dp[i][j] = max(
                    profit[i - 1] + dp[i - 1][j - weight[i - 1]],
                    dp[i - 1][j]
                );
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("Maximum profit = %d\n", dp[n][capacity]);

    return 0;
}
