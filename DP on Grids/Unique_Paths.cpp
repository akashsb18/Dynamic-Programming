// // RECURSION
// #include <bits/stdc++.h>
// using namespace std;

// int f(int i, int j)
// {
//     if (i == 0 and j == 0)
//     {
//         return 1;
//     }
//     if (i < 0 or j < 0)
//     {
//         return 0;
//     }
//     int up = f(i - 1, j);
//     int left = f(i, j - 1);

//     return up + left;
// }

// int main()
// {

//     int m = 3, n = 7;
//     cout << f(m - 1, n - 1);

//     return 0;
// }

// //MEMOIZATION
// #include <bits/stdc++.h>
// using namespace std;

// int f(int i, int j, vector<vector<int>> &dp)
// {
//     if (i == 0 and j == 0)
//     {
//         return 1;
//     }
//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }
//     if (i < 0 or j < 0)
//     {
//         return 0;
//     }
//     int up = f(i - 1, j, dp);
//     int left = f(i, j - 1, dp);

//     return dp[i][j] = up + left;
// }

// int main()
// {

// int m = 3, n = 7;
// vector<vector<int>> dp(m, vector<int>(n, -1));
// cout << f(m - 1, n - 1, dp);

//     return 0;
// }

// TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int m = 3, n = 7;
//     int dp[m][n];

// for (int i = 0; i < m; i++)
// {
//     for (int j = 0; j < n; j++)
//     {
//         if (i == 0 and j == 0)
//         {
//             dp[i][j] = 1;
//         }
//         else
//         {
//             int up = 0, left = 0;
//             if (i > 0)
//             {
//                 up = dp[i - 1][j];
//             }
//             if (j > 0)
//             {
//                 left = dp[i][j - 1];
//             }
//             dp[i][j] = up + left;
//         }
//     }
// }

//     cout << dp[m - 1][n - 1];

//     return 0;
// }

// 63. Unique Paths II

// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal to 2 * 109.

// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right

// RECURSION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int i, int j, vector<vector<int>> v)
// {
//     if (i >= 0 and j >= 0 and v[i][j] == 1) // JUST ONE CONDITION
//     {
//         return 0;
//     }
//     if (i == 0 and j == 0)
//     {
//         return 1;
//     }
//     if (i < 0 or j < 0)
//     {
//         return 0;
//     }
//     int up = f(i - 1, j, v);
//     int left = f(i, j - 1, v);

//     return up + left;
// }

// int main()
// {
//     vector<vector<int>> obstacleGrid = {
//         {0, 0, 0},
//         {0, 1, 0},
//         {0, 0, 0}};
//     int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//     cout << f(m - 1, n - 1, obstacleGrid);

//     return 0;
// }

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp)
// {
//     if (i >= 0 and j >= 0 and v[i][j] == 1) // JUST ONE CONDITION
//     {
//         return 0;
//     }
//     if (i == 0 and j == 0)
//     {
//         return 1;
//     }
//     if (i < 0 or j < 0)
//     {
//         return 0;
//     }
//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }
//     int up = f(i - 1, j, v, dp);
//     int left = f(i, j - 1, v, dp);

//     return dp[i][j] = up + left;
// }

// int main()
// {
//     vector<vector<int>> obstacleGrid = {
//         {1, 0}};

//     int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//     vector<vector<int>> dp(m, vector<int>(n, -1));

//     cout << f(m - 1, n - 1, obstacleGrid, dp);

//     return 0;
// }

// TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     vector<vector<int>> obstacleGrid = {
//         {0, 0, 0},
//         {0, 1, 0},
//         {0, 0, 0}};

//     int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//     vector<vector<int>> dp(m, vector<int>(n, -1));

//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i == 0 and j == 0)
//             {
//                 dp[i][j] = 1;
//             }
//             else if (obstacleGrid[i][j] == 1)
//             {
//                 dp[i][j] = 0;
//             }
//             else
//             {
//                 int up = 0, left = 0;
//                 if (i > 0)
//                 {
//                     up = dp[i - 1][j];
//                 }
//                 if (j > 0)
//                 {
//                     left = dp[i][j - 1];
//                 }
//                 dp[i][j] = up + left;
//             }
//         }
//     }

//     cout << dp[m - 1][n - 1];

//     return 0;
// }
