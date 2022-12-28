// Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].

// RECURSION

// #include <bits/stdc++.h>
// using namespace std;

// bool f(int ind, int target, vector<int> &v)
// {
//     if (target == 0)
//     {
//         return true;
//     }
//     if (ind == 0)
//     {
//         return (v[ind] == target);
//     }
//     bool notTake = f(ind - 1, target, v);
//     bool take = false;
//     if (target >= v[ind])
//     {
//         take = f(ind - 1, target - v[ind], v);
//     }

//     return take or notTake;
// }

// int main()
// {

//     vector<int> nums = {1, 5, 11, 5};
//     int n = nums.size();

//     int sum = accumulate(nums.begin(), nums.end(), 0);

//     if (sum % 2 != 0)
//     {
//         cout << false;
//     }
//     else
//     {
//         int k = sum / 2;
//         cout << f(n - 1, k, nums);
//     }

//     return 0;
// }

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// bool f(int ind, int target, vector<int> &v, vector<vector<int>> &dp)
// {
//     if (target == 0)
//     {
//         return true;
//     }
//     if (ind == 0)
//     {
//         return (v[ind] == target);
//     }
//     if (dp[ind][target] != -1)
//     {
//         return dp[ind][target];
//     }
//     bool notTake = f(ind - 1, target, v, dp);
//     bool take = false;
//     if (target >= v[ind])
//     {
//         take = f(ind - 1, target - v[ind], v, dp);
//     }

//     return dp[ind][target] = take or notTake;
// }

// int main()
// {

// vector<int> nums = {1, 5, 11, 5};
// int n = nums.size();

// int sum = accumulate(nums.begin(), nums.end(), 0);

// if (sum % 2 != 0)
// {
//     cout << false;
// }
//     else
//     {
//         int k = sum / 2;
//         vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

//         cout << f(n - 1, k, nums, dp);
//     }

//     return 0;
// }

// TABULATION

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> nums = {99, 1};
    int n = nums.size();

    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % 2 != 0)
    {
        cout << false;
    }
    else
    {
        int k = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= k; target++)
            {
                bool notTake = dp[ind - 1][target];
                bool take = false;
                if (target >= nums[ind])
                {
                    take = dp[ind - 1][target - nums[ind]];
                }

                dp[ind][target] = take or notTake;
            }
        }

        cout << dp[n - 1][k];
    }

    return 0;
}