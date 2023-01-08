
#include <bits/stdc++.h>
using namespace std;

int main()
{

    string text1 = "AGGTAB", text2 = "GXTXAYB";

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
            // Have to include else because in recursion, it returns from this position
            else
            {
                dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
    }

    string s = "";

    int i = n, j = m;

    while (i > 0 and j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            s += text1[i - 1];

            i--;
            j--;
        }
        else if (dp[i][j - 1] > dp[i - 1][j])
        {
            j = j - 1;
        }
        else
        {
            i = i - 1;
        }
    }

    reverse(s.begin(), s.end());

    cout << s;

    return 0;
}