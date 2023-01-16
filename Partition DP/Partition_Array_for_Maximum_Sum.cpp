// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

// Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

// Example 1:

// Input: arr = [1,15,7,9,2,5,10], k = 3
// Output: 84
// Explanation: arr becomes [15,15,15,9,10,10,10]
// Example 2:

// Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
// Output: 83

// #include <bits/stdc++.h>
// using namespace std;

// int f(int i, int n, int k, vector<int> &v)
// {
//     if (i == n)
//     {
//         return 0;
//     }
//     int maxi = -1e9, length = 0, sum = 0, maxSum = -1e9;
//     for (int j = i; j < min(i + k, n); j++)
//     {
//         length++;
//         maxi = max(maxi, v[j]);
//         sum = length * maxi + f(j + 1, n, k, v);
//         maxSum = max(maxSum, sum);
//     }

//     return maxSum;
// }

// int main()
// {

// vector<int> arr = {1, 15, 7, 9, 2, 5, 10};

// int k = 3, n = arr.size();

// cout << f(0, n, k, arr);

//     return 0;
// }

// Memoization

// #include <bits/stdc++.h>
// using namespace std;

// int f(int i, int n, int k, vector<int> &v, vector<int> &dp)
// {
//     if (i == n)
//     {
//         return 0;
//     }
//     if (dp[i] != -1)
//     {
//         return dp[i];
//     }
//     int maxi = -1e9, length = 0, sum = 0, maxSum = -1e9;
// for (int j = i; j < min(i + k, n); j++)
// {
//     length++;
//     maxi = max(maxi, v[j]);
//     sum = length * maxi + f(j + 1, n, k, v, dp);
//     maxSum = max(maxSum, sum);
// }

//     return dp[i] = maxSum;
// }

// int main()
// {
// vector<int> arr = {1, 15, 7, 9, 2, 5, 10};

// int k = 3, n = arr.size();

// vector<int> dp(n + 1, -1);

//     cout << f(0, n, k, arr, dp);

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};

    int k = 3, n = arr.size();

    vector<int> dp(n + 1, 0);

    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int maxi = -1e9, length = 0, sum = 0, maxSum = -1e9;

        for (int j = i; j < min(i + k, n); j++)
        {
            length++;
            maxi = max(maxi, arr[j]);
            sum = length * maxi + dp[j + 1];
            maxSum = max(maxSum, sum);
        }
        dp[i] = maxSum;
    }

    cout << dp[0];

    return 0;
}