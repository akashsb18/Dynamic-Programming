// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.

// The answer is guaranteed to fit into a signed 32-bit integer.

// Example 1:

// Input: amount = 5, coins = [1,2,5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1

// RECURSION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, int target, vector<int> &v)
// {

//     if (ind == 0)
//     {
//         if (target % v[0] == 0)
//         {
//             return 1;
//         }

//         return 0;
//     }

//     int notTake = 0 + f(ind - 1, target, v);
//     int take = 0;
//     if (target >= v[ind])
//     {
//         take = f(ind, target - v[ind], v);
//     }

//     return take + notTake;
// }

// int main()
// {

//     vector<int> coins = {1, 2, 5};
//     int amount = 5;
//     int n = coins.size();

//     cout << f(n - 1, amount, coins);

//     return 0;
// }

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, int target, vector<int> &v, vector<vector<int>> &dp)
// {

//     if (ind == 0)
//     {
//         if (target % v[0] == 0)
//         {
//             return 1;
//         }

//         return 0;
//     }
//     if (dp[ind][target] != -1)
//     {
//         return dp[ind][target];
//     }
//     int notTake = 0 + f(ind - 1, target, v, dp);
//     int take = 0;
//     if (target >= v[ind])
//     {
//         take = f(ind, target - v[ind], v, dp);
//     }

//     return dp[ind][target] = take + notTake;
// }

// int main()
// {

// vector<int> coins = {1, 2, 5};
// int amount = 5;
// int n = coins.size();
// vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
//     cout << f(n - 1, amount, coins, dp);

//     return 0;
// }

// TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     vector<int> coins = {1, 2, 5};
//     int amount = 5;
//     int n = coins.size();
//     vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

//     for (int i = 0; i <= amount; i++)
//     {
//         if (i % coins[0] == 0)
//         {
//             dp[0][i] = 1;
//         }
//     }

//     for (int ind = 1; ind < n; ind++)
//     {
//         for (int target = 0; target <= amount; target++)
//         {
//             int notTake = dp[ind - 1][target];
//             int take = 0;
//             if (target >= coins[ind])
//             {
//                 take = dp[ind][target - coins[ind]];
//             }
//             dp[ind][target] = take + notTake;
//         }
//     }

//     cout << dp[n - 1][amount];

//     return 0;
// }

// SPACE OPTIMISATION

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> coins = {1, 2, 5};
    int amount = 5;
    int n = coins.size();
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
        {
            prev[i] = 1;
        }
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= amount; target++)
        {
            int notTake = prev[target];
            int take = 0;
            if (target >= coins[ind])
            {
                take = curr[target - coins[ind]];
            }
            curr[target] = take + notTake;
        }
        prev = curr;
    }

    cout << prev[amount];

    return 0;
}