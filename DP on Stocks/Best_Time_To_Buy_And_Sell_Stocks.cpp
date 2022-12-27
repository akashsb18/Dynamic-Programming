// 122. Best Time to Buy and Sell Stock II

// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve.

// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.

// RECURSION
// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, bool buy, int n, vector<int> A)
// {
//     if (ind == n)
//     {
//         return 0;
//     }
//     int profit = 0;
//     if (buy)
//     {
//         profit = max(-A[ind] + f(ind + 1, false, n, A), 0 + f(ind + 1, true, n, A));
//     }
//     else
//     {
//         profit = max(A[ind] + f(ind + 1, true, n, A), 0 + f(ind + 1, false, n, A));
//     }
//     return profit;
// }

// int main()
// {

//     vector<int> A = {7, 1, 5, 3, 6, 4};
//     int n = A.size();
//     cout << f(0, true, n, A);

//     return 0;
// }

// MEMOIZATION
// There are two parameters , IND and BUY,so we need 2D vector for memoization

// #include <bits/stdc++.h>
// using namespace std;

// // Buy=True-->We can buy on the next day
// // Buy=False --> We cannot buy on the next day
// int f(int ind, int buy, int n, vector<int> A, vector<vector<int>> dp)
// {
//     if (ind == n)
//     {
//         return 0;
//     }
//     if (dp[ind][buy] != -1)
//     {
//         return dp[ind][buy];
//     }
//     int profit = 0;
//     if (buy)
//     {
//         profit = max(-A[ind] + f(ind + 1, 0, n, A, dp), 0 + f(ind + 1, 1, n, A, dp));
//     }
//     else
//     {
//         profit = max(A[ind] + f(ind + 1, 1, n, A, dp), 0 + f(ind + 1, 0, n, A, dp));
//     }
//     return dp[ind][buy] = profit;
// }

// int main()
// {

//     vector<int> A = {7, 1, 5, 3, 6, 4};
//     int n = A.size();
//     // IND will go from 0 to n and BUY will have two values i.e 0 and 1
//     vector<vector<int>> dp(n, vector<int>(2, -1));
//     cout << f(0, 1, n, A, dp);

//     return 0;
// }

// TABULATION --> reverse of recursion
// In recursion we went from 0 to n, therefore here we will go from n to 0

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     vector<int> prices = {7, 1, 5, 3, 6, 4};
//     int n = prices.size();
//     vector<vector<int>> dp(n + 1, vector<int>(2, -1));

//     dp[n][0] = dp[n][1] = 0;

// for (int ind = n - 1; ind >= 0; ind--)
// {
//     for (int buy = 1; buy >= 0; buy--)
//     {
//         int profit = 0;
//         if (buy == 1)
//         {
//             profit = max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
//         }
//         else
//         {
//             profit = max(prices[ind] + dp[ind + 1][1], 0 + dp[ind + 1][0]);
//         }

//         dp[ind][buy] = profit;
//     }
// }

//     cout << dp[0][1];

//     return 0;
// }

// OPTIMISED TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     vector<int> prices = {7, 1, 5, 3, 6, 4};
//     int n = prices.size();

//     vector<long> ahead(2, 0), cur(2, 0);

//     ahead[0] = ahead[1] = 0;

//     for (int ind = n - 1; ind >= 0; ind--)
//     {
//         for (int buy = 1; buy >= 0; buy--)
//         {
//             int profit = 0;
//             if (buy == 1)
//             {
//                 profit = max(-prices[ind] + ahead[0], 0 + ahead[1]);
//             }
//             else
//             {
//                 profit = max(prices[ind] + ahead[1], 0 + ahead[0]);
//             }

//             cur[buy] = profit;
//         }
//         ahead = cur;
//     }

//     cout << ahead[1];

//     return 0;
// }

// 123. Best Time to Buy and Sell Stock III

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete at most two transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

// RECURSION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, int buy, int cap, int n, vector<int> &v)
// {
//     if (cap == 0)
//     {
//         return 0;
//     }
//     if (ind == n)
//     {
//         return 0;
//     }
//     int profit = 0;
//     if (buy)
//     {
//         profit = max(-v[ind] + f(ind + 1, 0, cap, n, v), 0 + f(ind + 1, 1, cap, n, v));
//     }
//     else
//     {
//         profit = max(v[ind] + f(ind + 1, 1, cap - 1, n, v), 0 + f(ind + 1, 0, cap, n, v));
//     }

//     return profit;
// }
// int main()
// {

//     vector<int> v = {1, 2, 3, 4, 5};
//     int n = v.size();

//     cout << f(0, 1, 2, n, v);

//     return 0;
// }

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, int buy, int cap, int n, vector<int> &v, vector<vector<vector<int>>> &dp)
// {
//     if (cap == 0)
//     {
//         return 0;
//     }
//     if (ind == n)
//     {
//         return 0;
//     }
//     if (dp[ind][buy][cap] != -1)
//     {
//         return dp[ind][buy][cap];
//     }
//     int profit = 0;
//     if (buy)
//     {
//         profit = max(-v[ind] + f(ind + 1, 0, cap, n, v, dp), 0 + f(ind + 1, 1, cap, n, v, dp));
//     }
//     else
//     {
//         profit = max(v[ind] + f(ind + 1, 1, cap - 1, n, v, dp), 0 + f(ind + 1, 0, cap, n, v, dp));
//     }

//     return dp[ind][buy][cap] = profit;
// }

// int main()
// {

//     vector<int> v = {1, 2, 3, 4, 5};
//     int n = v.size();

//     vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));

//     cout << f(0, 1, 2, n, v, dp);

//     return 0;
// }

// TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     vector<int> v = {3, 3, 5, 0, 0, 3, 1, 4};
//     int n = v.size();

//     vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0))); // Initialised to 0
//     for (int ind = n - 1; ind >= 0; ind--)
//     {
//         for (int buy = 1; buy >= 0; buy--)
//         {
//             for (int cap = 2; cap >= 0; cap--)
//             {
//                 int profit = 0;
//                 if (buy)
//                 {
//                     profit = max(-v[ind] + dp[ind + 1][0][cap], 0 + dp[ind + 1][1][cap]);
//                 }
//                 else
//                 {
//                     profit = max(v[ind] + dp[ind + 1][1][cap - 1], 0 + dp[ind + 1][0][cap]);
//                 }

//                 dp[ind][buy][cap] = profit;
//             }
//         }
//     }

//     cout << dp[0][1][2];

//     return 0;
// }

// 309. Best Time to Buy and Sell Stock with Cooldown

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Input: prices = [1,2,3,0,2]
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]

// SAME AS Best Time to Buy and Sell Stock II except just 1 consition

// RECURSION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, bool buy, int n, vector<int> A)
// {
//     if (ind >= n) // Changes
//     {
//         return 0;
//     }
//     int profit = 0;
//     if (buy)
//     {
//         profit = max(-A[ind] + f(ind + 1, false, n, A), 0 + f(ind + 1, true, n, A));
//     }
//     else
//     {
//         profit = max(A[ind] + f(ind + 2, true, n, A), 0 + f(ind + 1, false, n, A)); // Changes
//     }
//     return profit;
// }

// int main()
// {

//     vector<int> A = {1, 2, 3, 0, 2};
//     int n = A.size();
//     cout << f(0, true, n, A);

//     return 0;
// }

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// // Buy=True-->We can buy on the next day
// // Buy=False --> We cannot buy on the next day
// int f(int ind, int buy, int n, vector<int> A, vector<vector<int>> dp)
// {
//     if (ind >= n)
//     {
//         return 0;
//     }
//     if (dp[ind][buy] != -1)
//     {
//         return dp[ind][buy];
//     }
//     int profit = 0;
//     if (buy)
//     {
//         profit = max(-A[ind] + f(ind + 1, 0, n, A, dp), 0 + f(ind + 1, 1, n, A, dp));
//     }
//     else
//     {
//         profit = max(A[ind] + f(ind + 2, 1, n, A, dp), 0 + f(ind + 1, 0, n, A, dp));
//     }
//     return dp[ind][buy] = profit;
// }

// int main()
// {

//     vector<int> A = {1, 2, 3, 0, 2};
//     int n = A.size();
//     // IND will go from 0 to n and BUY will have two values i.e 0 and 1
//     vector<vector<int>> dp(n, vector<int>(2, -1));
//     cout << f(0, 1, n, A, dp);

//     return 0;
// }

// TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     vector<int> prices = {1, 2, 3, 0, 2};
//     int n = prices.size();
//     vector<vector<int>> dp(n + 1, vector<int>(2, -1));

//     dp[n][0] = dp[n][1] = 0;

//     for (int ind = n - 1; ind >= 0; ind--)
//     {
//         for (int buy = 1; buy >= 0; buy--)
//         {
//             int profit = 0;
//             if (buy == 1)
//             {
//                 profit = max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
//             }
//             else
//             {
//                 profit = max(prices[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]);
//             }

//             dp[ind][buy] = profit;
//         }
//     }

//     cout << dp[0][1];

//     return 0;
// }

// 188. Best Time to Buy and Sell Stock IV

// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

// RECURSION

// Same as Best Time to Buy and Sell Stock III

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, int buy, int cap, int n, vector<int> &v)
// {
//     if (cap == 0)
//     {
//         return 0;
//     }
//     if (ind == n)
//     {
//         return 0;
//     }
//     int profit = 0;
//     if (buy)
//     {
//         profit = max(-v[ind] + f(ind + 1, 0, cap, n, v), 0 + f(ind + 1, 1, cap, n, v));
//     }
//     else
//     {
//         profit = max(v[ind] + f(ind + 1, 1, cap - 1, n, v), 0 + f(ind + 1, 0, cap, n, v));
//     }

//     return profit;
// }
// int main()
// {

//     vector<int> v = {3, 2, 6, 5, 0, 3, 2, 34, 5, 4, 2};
//     int n = v.size();
//     int k = 2;
//     cout << f(0, 1, k, n, v); // Just that the value of cap will change , thats it.

//     return 0;
// }

// MEMOIZATION

#include <bits/stdc++.h>
using namespace std;

int f(int ind, int buy, int cap, int n, vector<int> &v, vector<vector<vector<int>>> &dp)
{
    if (cap == 0)
    {
        return 0;
    }
    if (ind == n)
    {
        return 0;
    }
    if (dp[ind][buy][cap] != -1)
    {
        return dp[ind][buy][cap];
    }
    int profit = 0;
    if (buy)
    {
        profit = max(-v[ind] + f(ind + 1, 0, cap, n, v, dp), 0 + f(ind + 1, 1, cap, n, v, dp));
    }
    else
    {
        profit = max(v[ind] + f(ind + 1, 1, cap - 1, n, v, dp), 0 + f(ind + 1, 0, cap, n, v, dp));
    }

    return dp[ind][buy][cap] = profit;
}

int main()
{

    vector<int> v = {3, 3, 5, 0, 0, 3, 1, 4, 2, 3, 5, 4, 3, 1, 7, 6, 4, 3, 5, 4, 7, 9};
    int n = v.size();
    int k = 9;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));

    cout << f(0, 1, k, n, v, dp);

    return 0;
}

// TABULTION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     vector<int> v = {3, 3, 5, 0, 0, 3, 1, 4, 2, 3, 5, 4, 3, 1, 7, 6, 4, 3, 5, 4, 7, 9};
//     int n = v.size();
//     int k = 7;
//     vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0))); // Initialised to 0
//     for (int ind = n - 1; ind >= 0; ind--)
//     {
//         for (int buy = 1; buy >= 0; buy--)
//         {
//             for (int cap = 2; cap >= 0; cap--)
//             {
//                 int profit = 0;
//                 if (buy)
//                 {
//                     profit = max(-v[ind] + dp[ind + 1][0][cap], 0 + dp[ind + 1][1][cap]);
//                 }
//                 else
//                 {
//                     profit = max(v[ind] + dp[ind + 1][1][cap - 1], 0 + dp[ind + 1][0][cap]);
//                 }

//                 dp[ind][buy][cap] = profit;
//             }
//         }
//     }

//     cout << dp[0][1][k];

//     return 0;
// }