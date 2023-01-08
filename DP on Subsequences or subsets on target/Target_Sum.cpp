// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

// RECURSION

// S1-S2=target --> S1-(totalsum-S1)=D --> 2S1-totalsum=D --> S1=(D+totalsum)/2

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, int target, vector<int> &v)
// {
//     if (ind == 0)
//     {
//         if (target == 0 and v[0] == 0)
//         {
//             return 2;
//         }
//         if (target == 0 or v[0] == target)
//         {
//             return 1;
//         }
//         return 0;
//     }

//     int notTake = f(ind - 1, target, v);
//     int take = 0;
//     if (target >= v[ind])
//     {
//         take = f(ind - 1, target - v[ind], v);
//     }

//     return notTake + take;
// }

// int main()
// {

//     vector<int> nums = {1, 1, 1, 1, 1};
//     int n = nums.size();
//     int target = 3;
//     int totalSum = accumulate(nums.begin(), nums.end(), 0);
//     int newTarget = (totalSum + target) / 2;
//     if ((totalSum + target) % 2 != 0)
//     {
//         cout << 0;
//     }
//     else
//     {
//         cout << f(n - 1, newTarget, nums);
//     }

//     return 0;
// }

// MEMOIZATION
// //Does not work for this case.
// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, int target, vector<int> &v, vector<vector<int>> &dp)
// {
//     if (ind == 0)
//     {
//         if (target == 0 and v[0] == 0)
//         {
//             return 2;
//         }
//         if (target == 0 or v[0] == target)
//         {
//             return 1;
//         }
//         return 0;
//     }

//     if (dp[ind][target] != -1)
//     {
//         return dp[ind][target];
//     }

//     int notTake = f(ind - 1, target, v, dp);
//     int take = 0;
//     if (target >= v[ind])
//     {
//         take = f(ind - 1, target - v[ind], v, dp);
//     }

//     return dp[ind][target] = notTake + take;
// }

// int main()
// {

//     vector<int> nums = {100};
//     int n = nums.size();
//     int target = -200;
//     int totalSum = accumulate(nums.begin(), nums.end(), 0);
//     int newTarget = (totalSum + target) / 2;
//     if ((totalSum + target) % 2 != 0)
//     {
//         cout << 0;
//     }
//     else
//     {
//         vector<vector<int>> dp(n + 1, vector<int>(newTarget + 1, -1));
//         cout << f(n - 1, newTarget, nums, dp);
//     }

//     return 0;
// }

// TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     vector<int> arr = {1, 1, 1, 1, 1};
//     int totalSum = accumulate(arr.begin(), arr.end(), 0);
//     int target = 3;
//     int k = (target + totalSum) / 2;

//     int n = arr.size();
//     if ((target + totalSum) % 2 != 0)
//     {
//         cout << 0;
//     }
//     else
//     {

//         vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

//         if (arr[0] == 0)
//         {
//             dp[0][0] = 2;
//         }
//         else
//         {
//             dp[0][0] = 1;
//         }
//         if (arr[0] != 0 and arr[0] <= k)
//         {
//             dp[0][arr[0]] = 1;
//         }

//         for (int ind = 1; ind < n; ind++)
//         {
//             for (int newTarget = 0; newTarget <= k; newTarget++)
//             {

//                 int notTake = dp[ind - 1][newTarget];
//                 int take = 0;
//                 if (newTarget >= arr[ind])
//                 {
//                     take = dp[ind - 1][newTarget - arr[ind]];
//                 }

//                 dp[ind][newTarget] = take + notTake;
//             }
//         }

//         cout << dp[n - 1][k];
//     }

//     return 0;
// }

// SPACE OPTIMISATION

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr = {1, 1, 1, 1, 1};
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int d = 3;
    int k = (d + totalSum) / 2;

    int n = arr.size();
    if ((d + totalSum) % 2 != 0)
    {
        cout << 0;
    }
    else
    {

        // vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        vector<int> prev(k + 1, 0), curr(k + 1, 0);

        if (arr[0] == 0)
        {
            prev[0] = 2;
        }
        else
        {
            prev[0] = 1;
        }
        if (arr[0] != 0 and arr[0] <= k)
        {
            prev[arr[0]] = 1;
        }

        for (int ind = 1; ind < n; ind++)
        {
            // Initialize the curr array to all zeros
            fill(curr.begin(), curr.end(), 0);

            for (int target = 0; target <= k; target++)
            {
                int notTake = prev[target];
                int take = 0;
                if (target >= arr[ind])
                {
                    take = prev[target - arr[ind]];
                }

                curr[target] = take + notTake;
            }
            // Copy the values from the curr array into the prev array
            copy(curr.begin(), curr.end(), prev.begin());
        }

        cout << prev[k];
    }

    return 0;
}