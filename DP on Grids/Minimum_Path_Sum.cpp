// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

// RECURSION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int i, int j, vector<vector<int>> &v)
// {

//     if (i == 0 and j == 0)
//     {
//         return v[i][j];
//     }
//     if (i < 0 or j < 0)
//     {
//         return 1e9; // So that the path takes the maximum cost and won't get calculated
//     }
//     int up = f(i - 1, j, v) + v[i][j];
//     int left = f(i, j - 1, v) + v[i][j];

//     return min(up, left);
// }

// int main()
// {
//     vector<vector<int>> grid = {
//         {1, 3, 1},
//         {1, 5, 1},
//         {4, 2, 1}};
//     int m = grid.size(), n = grid[0].size();
//     cout << f(m - 1, n - 1, grid);

//     return 0;
// }

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp)
// {

//     if (i == 0 and j == 0)
//     {
//         return v[i][j];
//     }
//     if (i < 0 or j < 0)
//     {
//         return 1e9; // So that the path takes the maximum cost and won't get calculated
//     }
//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }
//     int up = f(i - 1, j, v, dp) + v[i][j];
//     int left = f(i, j - 1, v, dp) + v[i][j];

//     return dp[i][j] = min(up, left);
// }

// int main()
// {
//     vector<vector<int>> grid = {
//         {1, 3, 1},
//         {1, 5, 1},
//         {4, 2, 1}};
//     int m = grid.size(), n = grid[0].size();
//     vector<vector<int>> dp(m, vector<int>(n, -1));

//     cout << f(m - 1, n - 1, grid, dp);

//     return 0;
// }

// TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     vector<vector<int>> grid = {
//         {1, 3, 1},
//         {1, 5, 1},
//         {4, 2, 1}};
//     int m = grid.size(), n = grid[0].size();
//     int dp[m][n];

//     for (int i = 0; i < m; i++)
//     {

//         for (int j = 0; j < n; j++)
//         {
//             if (i == 0 and j == 0)
//             {
//                 dp[i][j] = grid[i][j];
//             }
//             else
//             {

//                 int up = grid[i][j];
//                 if (i > 0)
//                 {
//                     up += dp[i - 1][j];
//                 }
//                 else
//                 {
//                     up += 1e9;
//                 }
//                 int left = grid[i][j];
//                 if (j > 0)
//                 {
//                     left += dp[i][j - 1];
//                 }
//                 else
//                 {
//                     left += 1e9;
//                 }

//                 dp[i][j] = min(up, left);
//             }
//         }
//     }

//     cout << dp[m - 1][n - 1];

//     return 0;
// }

// SPACE OPTIMISATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     vector<vector<int>> grid = {
//         {1, 3, 1},
//         {1, 5, 1},
//         {4, 2, 1}};
//     int m = grid.size(), n = grid[0].size();
//     int dp[m][n];
//     vector<int> curr(n, 0), prev(m, 0);
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i == 0 and j == 0)
//             {
//                 curr[j] = grid[i][j];
//             }
//             else
//             {

//                 int up = grid[i][j];
//                 if (i > 0)
//                 {
//                     // requiring previous rows j column
//                     up += prev[j];
//                 }
//                 else
//                 {
//                     up += 1e9;
//                 }
//                 int left = grid[i][j];
//                 if (j > 0)
//                 {
//                     // requiring current rows j-1 column
//                     left += curr[j - 1];
//                 }
//                 else
//                 {
//                     left += 1e9;
//                 }

//                 curr[j] = min(up, left);
//             }
//         }
//         prev = curr;
//     }

//     cout << prev[n - 1];

//     return 0;
// }