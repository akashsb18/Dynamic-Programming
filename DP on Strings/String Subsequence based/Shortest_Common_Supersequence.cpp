// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

// A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

// Example 1:

// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation:
// str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
// str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
// The answer provided is the shortest such string that satisfies these properties.

//  Approach --> Common elements should be taken once i.e LCS concept
// Therefore , we can say that the length of the shortest supersequence will be ** n + m - length(LCS) **

// Need to know tabulation for these, watch strivers video again if confused

#include <bits/stdc++.h>
using namespace std;

int main()
{

    string text1 = "abcde", text2 = "fghij";

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

    // int length = n + m - dp[n][m];
    // cout << length;
    string ans = "";
    int i = n, j = m;
    while (i > 0 and j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            ans += text1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans += text1[i - 1];
            i--;
        }
        else
        {
            ans += text2[j - 1];
            j--;
        }
    }

    while (i > 0)
    {
        ans += text1[i - 1];
        i--;
    }
    while (j > 0)
    {
        ans += text2[j - 1];
        j--;
    }

    reverse(ans.begin(), ans.end());

    cout << ans;

    return 0;
}