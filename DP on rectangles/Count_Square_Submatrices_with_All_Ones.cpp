// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

// Example 1:

// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15
// Explanation:
// There are 10 squares of side 1.
// There are 4 squares of side 2.
// There is  1 square of side 3.
// Total number of squares = 10 + 4 + 1 = 15.

// On Dp on rectangles type of question, we tend to write tabulation code rather than recursion
// First we create a DP matrix of size n x n

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> v = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    int n = v.size(), m = v[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = v[i][0];
    }
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = v[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum += dp[i][j];
        }
    }
    cout << sum;

    return 0;
}