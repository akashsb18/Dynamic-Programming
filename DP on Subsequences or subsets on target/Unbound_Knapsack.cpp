// A thief wants to rob a store. He is carrying a bag of capacity W. The store has ‘n’ items of infinite supply. Its weight is given by the ‘wt’ array and its value by the ‘val’ array. He can either include an item in its knapsack or exclude it but can’t partially have it as a fraction. We need to find the maximum value of items that the thief can steal. He can take a single item any number of times he wants and put it in his knapsack.

// Input
//  W --> 15
//  7 2 4
//  5 10 20

// Output -- > 21

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, int W, vector<int> profit, vector<int> weight)
// {

//     if (ind == 0)
//     {
//         if (W >= weight[0])
//         {
//             return W / weight[0] * profit[0];
//         }
//         return 0;
//     }

//     int notTake = f(ind - 1, W, profit, weight);
//     int take = -1e9;
//     if (W >= weight[ind])
//     {
//         take = profit[ind] + f(ind, W - weight[ind], profit, weight);
//     }

//     return max(take, notTake);
// }

// int main()
// {

//     vector<int> profit = {7, 2, 4}, weight = {5, 10, 20};
//     int W = 15;

//     int n = profit.size();

//     cout << f(n - 1, W, profit, weight);

//     return 0;
// }

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, int W, vector<int> profit, vector<int> weight, vector<vector<int>> dp)
// {

//     if (ind == 0)
//     {
// if (W >= weight[0])
// {
//     return W / weight[0] * profit[0];
// }
//         return 0;
//     }
//     if (dp[ind][W] != -1)
//     {
//         return dp[ind][W];
//     }
// int notTake = f(ind - 1, W, profit, weight, dp);
// int take = -1e9;
// if (W >= weight[ind])
// {
//     take = profit[ind] + f(ind, W - weight[ind], profit, weight, dp);
// }

//     return dp[ind][W] = max(take, notTake);
// }

// int main()
// {

// vector<int> profit = {7, 2, 4}, weight = {5, 10, 20};
// int W = 15;

// int n = profit.size();
// vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
// cout << f(n - 1, W, profit, weight, dp);

//     return 0;
// }

// TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     vector<int> profit = {4, 1, 10}, weight = {1, 3, 9};
//     int w = 12;

//     int n = profit.size();
//     vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

//     for (int i = weight[0]; i <= w; i++)
//     {
//         dp[0][i] = (int)i / weight[0] * profit[0];
//     }

//     for (int ind = 1; ind < n; ind++)
//     {
//         for (int W = 0; W <= w; W++)
//         {
//             int notTake = dp[ind - 1][W];
//             int take = -1e9;
//             if (W >= weight[ind])
//             {
//                 take = profit[ind] + dp[ind][W - weight[ind]];
//             }
//             dp[ind][W] = max(notTake, take);
//         }
//     }

//     cout << dp[n - 1][w];

//     return 0;
// }

// SPACE OPTIMIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     vector<int> profit = {4, 1, 10}, weight = {1, 3, 9};
//     int w = 12;

//     int n = profit.size();
//     vector<int> prev(w + 1, 0), curr(w + 1, 0);

//     for (int i = weight[0]; i <= w; i++)
//     {
//         prev[i] = (int)i / weight[0] * profit[0];
//     }

//     for (int ind = 1; ind < n; ind++)
//     {
//         for (int W = 0; W <= w; W++)
//         {
//             int notTake = prev[W];
//             int take = -1e9;
//             if (W >= weight[ind])
//             {
//                 take = profit[ind] + curr[W - weight[ind]];
//             }
//             curr[W] = max(notTake, take);
//         }
//         prev = curr;
//     }

//     cout << prev[w];

//     return 0;
// }

// 1-D array optimization

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> profit = {4, 1, 2, 3}, weight = {3, 4, 5, 1};
    int w = 7;

    int n = profit.size();
    vector<int> prev(w + 1, 0);

    for (int i = weight[0]; i <= w; i++)
    {
        prev[i] = (int)i / weight[0] * profit[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int W = 0; W <= w; W++)
        {
            int notTake = prev[W];
            int take = -1e9;
            if (W >= weight[ind])
            {
                take = profit[ind] + prev[W - weight[ind]];
            }
            prev[W] = max(notTake, take);
        }
    }

    cout << prev[w];

    return 0;
}
