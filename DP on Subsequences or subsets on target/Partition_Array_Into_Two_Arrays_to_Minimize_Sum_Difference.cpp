// You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

// Return the minimum possible absolute difference.

//  Input: nums = [3,9,7,3]
// Output: 2
// Explanation: One optimal partition is: [3,9] and [7,3].
// The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr = {1, 2, 3, 4};

    int n = arr.size();
    int totalSum = 0;
    totalSum = accumulate(arr.begin(), arr.end(), 0);

    vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, 0));

    for (int ind = 0; ind < n; ind++)
    {
        dp[ind][0] = true;
    }
    if (totalSum >= arr[0])
    {
        dp[0][arr[0]] = true;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= totalSum; target++)
        {
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if (arr[ind] <= target)
            {
                take = dp[ind - 1][target - arr[ind]];
            }

            dp[ind][target] = take or notTake;
        }
    }

    int mini = 1e9;
    for (int i = 0; i < totalSum / 2; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int s1 = i;
            int s2 = totalSum - i;
            mini = min(mini, abs(s1 - s2));
        }
    }

    cout << mini;

    return 0;
}