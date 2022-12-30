// You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.Note that we have only one quantity of each item.In other words, given two integer arrays val[0..N - 1] and wt[0..N - 1] which represent values and weights associated with N items respectively.Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.You cannot break an item, either pick the complete item or dont pick it(0 - 1 property).

//  Example 1 :

//     Input : N = 3 W = 4 values[] = {1, 2, 3} weight[] = {4, 5, 1} Output : 3

// SOLUTION

// (1) Express in terms of (ind,Weight)
// (2) Explore all possibilities i) Pick ii) Non Pick
// (3) Max of all possibilities

// f(n-1,W) --> Till index n-1, what maximum val you all can get with weight being W

// RECURSION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, int W, vector<int> &val, vector<int> &wht)
// {

//     if (ind == 0)
//     {
//         if (W >= wht[0])
//         {
//             return val[0];
//         }
//         else
//         {
//             return 0;
//         }
//     }

//     int notPick = 0 + f(ind - 1, W, val, wht);
//     int pick = -1e9;
//     if (W >= wht[ind])
//     {
//         pick = val[ind] + f(ind - 1, W - wht[ind], val, wht);
//     }

//     return max(pick, notPick);
// }

// int main()
// {

//     vector<int> values = {5, 4, 8, 6};
//     vector<int> weight = {1, 2, 4, 5};
//     int n = values.size();
//     int W = 5;

//     cout << f(n - 1, W, values, weight);

//     return 0;
// }

// TC --> O(2^n) , SC --> O(n)

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, int W, vector<int> &val, vector<int> &wht, vector<vector<int>> &dp)
// {

//     if (ind == 0)
//     {
//         if (W >= wht[0])
//         {
//             return val[0];
//         }
//         else
//         {
//             return 0;
//         }
//     }

//     if (dp[ind][W] != -1)
//     {
//         return dp[ind][W];
//     }

// int notPick = 0 + f(ind - 1, W, val, wht, dp);
// int pick = -1e9;
// if (W >= wht[ind])
// {
//     pick = val[ind] + f(ind - 1, W - wht[ind], val, wht, dp);
// }

//     return dp[ind][W] = max(pick, notPick);
// }

// int main()
// {

// vector<int> values = {5, 4, 8, 6};
// vector<int> weight = {1, 2, 4, 5};
// int n = values.size();
// int W = 5;
// vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
//     cout << f(n - 1, W, values, weight, dp);

//     return 0;
// }
// TC --> O(n x w)  SC --> O(n x w) + O(n)

// TABULTION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

// vector<int> values = {5, 4, 8, 6};
// vector<int> weight = {1, 2, 4, 5};
// int n = values.size();
// int W = 5;
// vector<vector<int>> dp(n, vector<int>(W + 1, 0));

// for (int i = weight[0]; i <= W; i++)
// {
//     dp[0][i] = values[0];
// }

// for (int ind = 1; ind < n; ind++)
// {
//     for (int wt = 0; wt <= W; wt++)
//     {
//         int notPick = 0 + dp[ind - 1][wt];
//         int pick = -1e9;
//         if (wt >= weight[ind])
//         {
//             pick = values[ind] + dp[ind - 1][wt - weight[ind]];
//         }
//         dp[ind][wt] = max(pick, notPick);
//     }
// }

// cout << dp[n - 1][W];

// return 0;
// }

// SPACE OPTIMIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     vector<int> values = {5, 4, 8, 6};
//     vector<int> weight = {1, 2, 4, 5};
//     int n = values.size();
//     int W = 5;
//     // vector<vector<int>> dp(n, vector<int>(W + 1, 0));

//     vector<int> prev(W + 1, 0), curr(W + 1, 0);

//     for (int i = weight[0]; i <= W; i++)
//     {
//         prev[i] = values[0];
//     }

//     for (int ind = 1; ind < n; ind++)
//     {
//         for (int wt = 0; wt <= W; wt++)
//         {
//             int notPick = 0 + prev[wt];
//             int pick = -1e9;
//             if (wt >= weight[ind])
//             {
//                 pick = values[ind] + prev[wt - weight[ind]];
//             }
//             curr[wt] = max(pick, notPick);
//         }

//         prev = curr;
//     }

//     cout << prev[W];

//     return 0;
// }

// Single array optimization

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> values = {5, 4, 8, 6};
    vector<int> weight = {1, 2, 4, 5};
    int n = values.size();
    int W = 5;
    // vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    vector<int> prev(W + 1, 0);

    for (int i = weight[0]; i <= W; i++)
    {
        prev[i] = values[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int wt = W; wt >= 0; wt--)
        {
            int notPick = 0 + prev[wt];
            int pick = -1e9;
            if (wt >= weight[ind])
            {
                pick = values[ind] + prev[wt - weight[ind]];
            }
            prev[wt] = max(pick, notPick);
        }
    }

    cout << prev[W];

    return 0;
}