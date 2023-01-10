// Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

// The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

// Example 1:

// Input: N = 5
// arr = {40, 20, 30, 10, 30}
// Output: 26000
// Explaination: There are 4 matrices of dimension
// 40x20, 20x30, 30x10, 10x30. Say the matrices are
// named as A, B, C, D. Out of all possible combinations,
// the most efficient way is (A*(B*C))*D.
// The number of operations are -
// 20*30*10 + 40*20*10 + 40*10*30 = 26000.

// #include <bits/stdc++.h>
// using namespace std;

// int f(int i, int j, vector<int> A, vector<vector<int>> dp)
// {
//     if (i == j)
//     {
//         return 0;
//     }
// int mini = 1e9;
// if (dp[i][j] != -1)
// {
//     return dp[i][j];
// }
// for (int k = i; k < j; k++)
// {
//     int steps = A[i - 1] * A[k] * A[j] + f(i, k, A, dp) + f(k + 1, j, A, dp);
//     mini = min(mini, steps);
// }
// return dp[i][j] = mini;
// }

// int main()
// {

// vector<int> arr = {10, 30, 5, 60};

// int n = arr.size();

// vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

//     cout << f(1, n - 1, arr, dp);

//     return 0;
// }

// // // TC --> O(n ^ 3) , SC --> O(n ^ 2) + O(n)

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> A = {10, 30, 5, 60};

    int n = A.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)

        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = A[i - 1] * A[k] * A[j] + dp[i][k] + dp[k + 1][j];
                if (steps < mini)
                {
                    mini = steps;
                }
            }
            dp[i][j] = mini;
        }
    }

    cout << dp[1][n - 1];

    return 0;
}