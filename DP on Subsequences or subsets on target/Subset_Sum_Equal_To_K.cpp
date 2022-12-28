// You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.

// Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

// For Example :
// If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.

// RECURSION

// #include <bits/stdc++.h>
// using namespace std;

// bool f(int ind, int target, vector<int> v)
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

//     return notTake or take;
// }

// int main()
// {

//     vector<int> arr = {2, 5, 1, 6, 7};
//     int k = 4;
//     int n = arr.size();

//     cout << f(n - 1, k, arr);

//     return 0;
// }

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// bool f(int ind, int target, vector<int> v, vector<vector<int>> &dp)
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

//     return dp[ind][target] = notTake or take;
// }

// int main()
// {

// vector<int> arr = {2, 5, 1, 6, 7};
// int k = 7;
// int n = arr.size();
// vector<vector<int>> dp(n + 1, vector<int>(k+1, -1));
// cout << f(n - 1, k, arr, dp);

//     return 0;
// }

// TABULATION

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr = {2, 5, 1, 6, 7};
    int k = 4;
    int n = arr.size();
    // bool dp[n][k + 1] = {0, 0, 0};
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    for (int ind = 0; ind < n; ind++)
    {
        dp[ind][0] = true;
    }
    dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
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

    cout << dp[n - 1][k];

    return 0;
}