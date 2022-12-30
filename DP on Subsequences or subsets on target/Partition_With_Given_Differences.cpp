// Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.

// Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer may be too large, return it modulo ‘10^9 + 7’.

// If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are considered different if:

// Arr = {5,2,5,1} , D=3 ,N=4;

//*******************************************
// S1-S2=D --> S1-(totalsum-S1)=D --> 2S1-totalsum=D --> S1=(D+totalsum)/2
//*******************************************

// RECURSION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, int target, vector<int> v)
// {

//     if (ind == 0)
//     {
//         if (target == 0 and v[0] == 0)
//         {
//             return 2;
//         }
//         if (target == 0 or target == v[0])
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

//     vector<int> arr = {3, 2, 2, 5, 1};
//     int totalSum = accumulate(arr.begin(), arr.end(), 0);
//     int d = 1;
//     int k = (d + totalSum) / 2;
//     int n = arr.size();
//     if ((totalSum + d) % 2 != 0)
//     {
//         cout << 0;
//     }
//     else
//     {
//         cout << f(n - 1, k, arr);
//     }

//     return 0;
// }

// // MEMOIZATION
// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, int target, vector<int> v, vector<vector<int>> &dp)
// {

//     if (ind == 0)
//     {
//         if (target == 0 and v[0] == 0)
//         {
//             return 2;
//         }
//         if (target == 0 or target == v[0])
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

//     vector<int> arr = {3, 2, 2, 5, 1};
// int totalSum = accumulate(arr.begin(), arr.end(), 0);
// int d = 1;
// int k = (d + totalSum) / 2;
//     int n = arr.size();
//     vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
//     if ((totalSum + d) % 2 != 0)
//     {
//         cout << 0;
//     }
//     else
//     {
//         cout << f(n - 1, k, arr, dp);
//     }

//     return 0;
// }

// TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     vector<int> arr = {3, 2, 2, 5, 1};
//     int totalSum = accumulate(arr.begin(), arr.end(), 0);
//     int d = 1;
//     int k = (d + totalSum) / 2;

//     int n = arr.size();
//     if ((d + totalSum) % 2 != 0)
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
//             for (int target = 0; target <= k; target++)
//             {

//                 int notTake = dp[ind - 1][target];
//                 int take = 0;
//                 if (target >= arr[ind])
//                 {
//                     take = dp[ind - 1][target - arr[ind]];
//                 }

//                 dp[ind][target] = take + notTake;
//             }
//         }

//         cout << dp[n - 1][k];
//     }

//     return 0;
// }

// Space optimization

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     vector<int> arr = {3, 2, 2, 5, 1};
//     int totalSum = accumulate(arr.begin(), arr.end(), 0);
//     int d = 1;
//     int k = (d + totalSum) / 2;

//     int n = arr.size();
//     if ((d + totalSum) % 2 != 0)
//     {
//         cout << 0;
//     }
//     else
//     {

//         // vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
//         vector<int> prev(k + 1, 0), curr(k + 1, 0);

//         if (arr[0] == 0)
//         {
//             prev[0] = 2;
//         }
//         else
//         {
//             prev[0] = 1;
//         }
//         if (arr[0] != 0 and arr[0] <= k)
//         {
//             prev[arr[0]] = 1;
//         }

//         for (int ind = 1; ind < n; ind++)
//         {
//             for (int target = 0; target <= k; target++)
//             {

//                 int notTake = prev[target];
//                 int take = 0;
//                 if (target >= arr[ind])
//                 {
//                     take = prev[target - arr[ind]];
//                 }

//                 curr[target] = take + notTake;
//             }
//             prev = curr;
//         }

//         cout << prev[k];
//     }

//     return 0;
// }
