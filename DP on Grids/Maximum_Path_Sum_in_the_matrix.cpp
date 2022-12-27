// NOTES WRITTEN COPY

// Given a matrix of N * M. Find the maximum path sum in matrix. The maximum path is sum of all elements from first row to last row where you are allowed to move only down or diagonally to left or right. You can start from any element in first row.

// Input : mat[][] = 10 10  2  0 20  4
//                    1  0  0 30  2  5
//                    0 10  4  0  2  0
//                    1  0  2 20  0  4
// Output : 74
// The maximum sum path is 20-30-4-20.

// Any cell in the first row to any cell in the last row.

// Here ,we will be starting from n-1 -> 0 .
// Need to consider every column of first row or second row depending upon where you start from

// f(i,j) --> maximum path sum to reach (i,j) from any cell in the first row.

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp)
// {
//     if (j < 0 or j > v[0].size())
//     {
//         return -1e8;
//     }
//     if (i == 0)
//     {
//         return v[0][j];
//     }
//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }
// int up = v[i][j] + f(i - 1, j, v, dp);
// int dleft = v[i][j] + f(i - 1, j - 1, v, dp);
// int dright = v[i][j] + f(i - 1, j + 1, v, dp);

//     return dp[i][j] = max(up, max(dleft, dright));
// }

// int main()
// {
//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {9, 8, 7},
//         {4, 5, 6},
//     };
//     int n = matrix.size(), m = matrix[0].size();
//     vector<vector<int>> dp(n, vector<int>(m, -1));
//     int maxi = -1e8;
//     for (int j = 0; j < m; j++)
//     {
//         maxi = max(maxi, f(n - 1, j, matrix, dp));       //We have to do this part because starting and ending are variable
//     }

//     cout << maxi;

//     // cout << m;

//     return 0;
// }

// TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {9, 8, 7},
//         {4, 5, 6}};
//     int n = matrix.size(), m = matrix[0].size();
//     int dp[n][m];

//     // Base Case
//     for (int j = 0; j < m; j++)
//     {
//         dp[0][j] = matrix[0][j];
//     }

//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             int dleft = 0, dright = 0;
//             int up = matrix[i][j] + dp[i - 1][j];
//             if (j - 1 > 0)
//             {
//                 dleft = matrix[i][j] + dp[i - 1][j - 1];
//             }
//             if (j + 1 < m)
//             {
//                 dright = matrix[i][j] + dp[i - 1][j + 1];
//             }

//             dp[i][j] = max(up, max(dleft, dright));
//         }
//     }

//     int maxi = -1e9;
//     for (int j = 0; j < m; j++)
//     {
//         maxi = max(maxi, dp[n - 1][j]);
//     }

//     cout << maxi;

//     return 0;
// }