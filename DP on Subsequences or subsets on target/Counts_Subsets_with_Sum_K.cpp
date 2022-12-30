// We are given an array ‘ARR’ with N positive integers and an integer K.We need to find the number of subsets whose sum is equal to K.

// Input
//  [1,2,2,3]   ans-> 3

// RECURSION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, int target, vector<int> v)
// {
//     if (target == 0)
//     {
//         return 1;
//     }
//     if (ind == 0)
//     {
//         if (v[0] == target)
//         {
//             return 1;
//         }
//         else
//         {
//             return 0;
//         }
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

//     vector<int> arr = {2, 3, 5, 6, 8, 10};
//     int k = 10;
//     int n = arr.size();

//     cout << f(n - 1, k, arr);

//     return 0;
// }
// TC --> O(2^n)  SC --> O(n)

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, int target, vector<int> v, vector<vector<int>> &dp)
// {
// if (ind == 0)
// {
//     if (target == 0 && v[0] == target)
//         return 2;
//     else if (v[0] == target || target == 0)
//         return 1;
//     else
//         return 0;
// }
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

//     vector<int> arr = {2, 3, 5, 6, 8, 10};
//     int k = 10;
//     int n = arr.size();

//     vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

//     cout << f(n - 1, k, arr, dp);

//     return 0;
// }
// TC -- > O(n x target)  SC --> O(n x target) + O(n)

// TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     vector<int> arr = {2, 3, 5, 6, 8, 10};
//     int k = 10;
//     int n = arr.size();

//     vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

//     for (int ind = 0; ind < n; ind++)
//     {
//         dp[ind][0] = 1;
//     }
//     if (k >= arr[0])
//     {
//         dp[0][arr[0]] = 1;
//     }

//     for (int ind = 1; ind < n; ind++)
//     {
//         for (int target = 0; target <= k; target++)
//         {

//             int notTake = dp[ind - 1][target];
//             int take = 0;
//             if (target >= arr[ind])
//             {
//                 take = dp[ind - 1][target - arr[ind]];
//             }

//             dp[ind][target] = take + notTake;
//         }
//     }

//     cout << dp[n - 1][k];

//     return 0;
// }

// // TC --> O(n x target)  , SC --> O (n x target)