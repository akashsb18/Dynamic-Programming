// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

// Solution

// f(n-1,Target)  --> Till length n-1, what is the minimum number of coins that will fir the target

// //RECURSION
// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, int T, vector<int> &v)
// {

// if (ind == 0)
// {
//     if (T % v[0] == 0)
//     {
//         return T / v[0];
//     }
//     return 1e9;
// }

// int notTake = 0 + f(ind - 1, T, v);
// int take = 1e9;
// if (T >= v[ind])
// {
//     take = 1 + f(ind, T - v[ind], v); // Whenever we have infinite case or multiple picking, ind will not decrease;
// }

//     return min(notTake, take);
// }

// int main()
// {

//     vector<int> coins = {1, 2, 5};
//     int amount = 11;

//     int n = coins.size();

//     cout << f(n - 1, amount, coins);

//     return 0;
// }

// TC --> >>O(2^n)  SC --> O(n);

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, int T, vector<int> &v, vector<vector<int>> &dp)
// {

//     if (ind == 0)
//     {
//         if (T % v[0] == 0)
//         {
//             return T / v[0];
//         }
//         return 1e9;
//     }
//     if (dp[ind][T] != -1)
//     {
//         return dp[ind][T];
//     }
//     int notTake = 0 + f(ind - 1, T, v, dp);
//     int take = 1e9;
//     if (T >= v[ind])
//     {
//         take = 1 + f(ind, T - v[ind], v, dp); // Whenever we have infinite case or multiple picking, ind will not decrease;
//     }

//     return dp[ind][T] = min(notTake, take);
// }

// int main()
// {

// vector<int> coins = {1, 2, 5};
// int amount = 11;

// int n = coins.size();
// vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
// cout << f(n - 1, amount, coins, dp);

//     return 0;
// }

// TC --> O( n x amount)  SC --> O(n x amount) + O(n);

// TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     vector<int> coins = {1, 2, 5};
//     int amount = 11;

//     int n = coins.size();
//     vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

//     for (int i = 0; i <= amount; i++)
//     {
//         if (i % coins[0] == 0)
//         {
//             dp[0][i] = i / coins[0];
//         }
//         else
//         {
//             dp[0][i] = 1e9;
//         }
//     }

//     for (int ind = 1; ind < n; ind++)
//     {
//         for (int T = 0; T <= amount; T++)
//         {
//             int notTake = 0 + dp[ind - 1][T];
//             int take = 1e9;
//             if (T >= coins[ind])
//             {
//                 take = 1 + dp[ind][T - coins[ind]];
//             }

//             dp[ind][T] = min(notTake, take);
//         }
//     }

//     cout << dp[n - 1][amount];

//     return 0;
// }

// TC --> O( n x amount)  SC --> O(n x amount);

// SPACE OPTIMIZATION

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int n = coins.size();
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
        {
            prev[i] = i / coins[0];
        }
        else
        {
            prev[i] = 1e9;
        }
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= amount; T++)
        {
            int notTake = 0 + prev[T];
            int take = 1e9;
            if (T >= coins[ind])
            {
                take = 1 + curr[T - coins[ind]];
            }

            curr[T] = min(notTake, take);
        }
        prev = curr;
    }

    cout << prev[amount];

    return 0;
}

// TC --> O(n x amount)  SC--> O(n + amount)