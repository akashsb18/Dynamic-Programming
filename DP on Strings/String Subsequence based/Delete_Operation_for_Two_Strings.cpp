// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

// In one step, you can delete exactly one character in either string.

// Input: word1 = "sea", word2 = "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

// Approach --> What can i not touch

// Watch striver DP for better underatsnding

// ** Longest Common Subsequences

#include <bits/stdc++.h>
using namespace std;

int main()
{

    string text1 = "leetcode", text2 = "etco";

    int n = text1.length(), m = text2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (text1[ind1 - 1] == text2[ind2 - 1])
            {
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            }
            else
            {
                dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
    }

    int deletion = n - dp[n][m];
    int insertion = m - dp[n][m];
    cout << n + m - 2 * dp[n][m]
         << endl;
    cout << deletion + insertion;

    return 0;
}