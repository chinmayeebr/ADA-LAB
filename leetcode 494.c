#include <stdio.h>
#include <stdlib.h>

int findTargetSumWays(int* nums, int numsSize, int target)
{
    int sum = 0;

    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
    }

    // Impossible case
    if ((sum + target) % 2 != 0 || abs(target) > sum)
    {
        return 0;
    }

    int s1 = (sum + target) / 2;

    int dp[s1 + 1];

    for (int i = 0; i <= s1; i++)
    {
        dp[i] = 0;
    }

    dp[0] = 1;

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = s1; j >= nums[i]; j--)
        {
            dp[j] = dp[j] + dp[j - nums[i]];
        }
    }

    return dp[s1];
}
