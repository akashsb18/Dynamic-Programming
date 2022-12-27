// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
// 2
// 3 4
// 6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

// SOLUTION

// Here, starting point is fixed, but ending point is variable
//(1) Represent (i,j)
//(2) Explore all paths
//(3) Minimum of all path

// Here, we can't start from end because their is no fixed end point .Therefore f(m-1,n-1) will not work.
// Here we will start from f(0,0), a as starting point is fixed
// Generally , destination is the base casae

// RECURSION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int i, int j, vector<vector<int>> &v, int n)
// {
//     if (i == n - 1)
//     {
//         return v[n - 1][j]; // Return any value that you are in, we know that it will be according to our recuirement
//     }
//     int down = f(i + 1, j, v, n) + v[i][j];
//     int diagonally = f(i + 1, j + 1, v, n) + v[i][j];

//     return min(down, diagonally);
// }

// int main()
// {

//     vector<vector<int>> triangle = {{2},
//                                     {3, 4},
//                                     {6, 5, 7},
//                                     {4, 1, 8, 3}};
//     int n = triangle.size();

//     cout << f(0, 0, triangle, n);

//     return 0;
// }

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int i, int j, vector<vector<int>> &v, int n, vector<vector<int>> &dp)
// {
//     if (i == n - 1)
//     {
//         return v[n - 1][j];
//     }
//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }
//     int down = f(i + 1, j, v, n, dp) + v[i][j];
//     int diagonally = f(i + 1, j + 1, v, n, dp) + v[i][j];

//     return dp[i][j] = min(down, diagonally);
// }

// int main()
// {

//     vector<vector<int>> triangle = {{2},
//                                     {3, 4},
//                                     {6, 5, 7},
//                                     {4, 1, 8, 3}};
//     int n = triangle.size();
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     cout << f(0, 0, triangle, n, dp);

//     return 0;
// }

// TC --> O(n x n) , SC --> O(n x n)+O(n)

// TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     vector<vector<int>> triangle = {{2},
//                                     {3, 4},
//                                     {6, 5, 7},
//                                     {4, 1, 8, 3}};
//     int n = triangle.size();
//     int dp[n][n];

//     for (int j = 0; j < n; j++)
//     {
//         dp[n - 1][j] = triangle[n - 1][j];
//     }
//     for (int i = n - 2; i >= 0; i--)
//     {
//         for (int j = i; j >= 0; j--)
//         {
//             int down = dp[i + 1][j] + triangle[i][j];
//             int diagonal = dp[i + 1][j + 1] + triangle[i][j];

//             dp[i][j] = min(down, diagonal);
//         }
//     }

//     cout << dp[0][0];
//     return 0;
// }

// TC --> O(n x n); SC--> O(n x n) for the matrix that we're using

// SPACE OPTIMISATION

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> triangle = {{2},
                                    {3, 4},
                                    {6, 5, 7},
                                    {4, 1, 8, 3}};
    int n = triangle.size();
    vector<int> front(n, 0), curr(n, 0);

    for (int j = 0; j < n; j++)
    {
        front[j] = triangle[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = front[j] + triangle[i][j];
            int diagonal = front[j + 1] + triangle[i][j];

            curr[j] = min(down, diagonal);
        }
        front = curr;
    }

    cout << curr[0];
    return 0;
}

// TC --> O(n x n) and SC --> O(n)