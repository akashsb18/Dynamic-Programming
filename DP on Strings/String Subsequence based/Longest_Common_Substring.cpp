// If we use recursion , we would require three variables. Therefore we will not prefer recursion. We will use tabulation concept from  previous problems
// See copy for DP table

#include <bits/stdc++.h>
using namespace std;

int main()
{

    string text1 = "abcd", text2 = "abzd";

    int n = text1.length(), m = text2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // HERE WE WILL DO SHIFTING BECAUSE WE DONT WANT T0 GIVE 0 indexing

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    // n-- > n - 1, 1 -- > 0
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
                dp[ind1][ind2] = 0; // CHANGES
            }
        }
    }
    int maxElement = -1e9;

    // checking each element of matrix
    // if it is greater than maxElement,
    // update maxElement
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (dp[i][j] > maxElement)
            {
                maxElement = dp[i][j];
            }
        }
    }

    cout << maxElement;

    return 0;
}