// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')

// f(n-1,m-1)  --> Find the minimum operation to convert string word1 to word2

// RECURSION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind1, int ind2, string &s1, string &s2)
// {

//     if (ind2 < 0)
//     {
//         return ind1 + 1;
//     }
//     if (ind1 < 0)
//     {
//         return ind2 + 1;
//     }

//     if (s1[ind1] == s2[ind2])
//     {
//         return 0 + f(ind1 - 1, ind2 - 1, s1, s2);
//     }
//     int insert = 1 + f(ind1, ind2 - 1, s1, s2);
//     int Delete = 1 + f(ind1 - 1, ind2, s1, s2);
//     int replace = 1 + f(ind1 - 1, ind2 - 1, s1, s2);

//     return min(insert, min(Delete, replace));
// }

// int main()
// {

//     string word1 = "intention", word2 = "execution";

//     int n = word1.length(), m = word2.length();

//     cout << f(n - 1, m - 1, word1, word2);

//     return 0;
// }

// TC --> O(3^(m+n))  SC --> O(n+m)

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp)
// {

//     if (ind2 < 0)
//     {
//         return ind1 + 1;
//     }
//     if (ind1 < 0)
//     {
//         return ind2 + 1;
//     }

//     if (dp[ind1][ind2] != -1)
//     {
//         return dp[ind1][ind2];
//     }

//     if (s1[ind1] == s2[ind2])
//     {
//         return 0 + f(ind1 - 1, ind2 - 1, s1, s2, dp);
//     }
//     int insert = 1 + f(ind1, ind2 - 1, s1, s2, dp);
//     int Delete = 1 + f(ind1 - 1, ind2, s1, s2, dp);
//     int replace = 1 + f(ind1 - 1, ind2 - 1, s1, s2, dp);

//     return dp[ind1][ind2] = min(insert, min(Delete, replace));
// }

// int main()
// {

//     string word1 = "intention", word2 = "execution";

//     int n = word1.length(), m = word2.length();

//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

//     cout << f(n - 1, m - 1, word1, word2, dp);

//     return 0;
// }

// After Shifting

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp)
// {

//     if (ind2 == 0)
//     {
//         return ind1;
//     }
//     if (ind1 == 0)
//     {
//         return ind2;
//     }

//     if (dp[ind1][ind2] != -1)
//     {
//         return dp[ind1][ind2];
//     }

// if (s1[ind1 - 1] == s2[ind2 - 1])
// {
//     return 0 + f(ind1 - 1, ind2 - 1, s1, s2, dp);
// }
// int insert = 1 + f(ind1, ind2 - 1, s1, s2, dp);
// int Delete = 1 + f(ind1 - 1, ind2, s1, s2, dp);
// int replace = 1 + f(ind1 - 1, ind2 - 1, s1, s2, dp);

// return dp[ind1][ind2] = min(insert, min(Delete, replace));
// }

// int main()
// {

// string word1 = "intention", word2 = "execution";

// int n = word1.length(), m = word2.length();

// vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

//     cout << f(n, m, word1, word2, dp);

//     return 0;
// }

// TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     string word1 = "sea", word2 = "eat";

//     int n = word1.length(), m = word2.length();

//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//     for (int i = 0; i <= n; i++)
//     {
//         dp[i][0] = i;
//     }
//     for (int j = 1; j <= m; j++)
//     {
//         dp[0][j] = j;
//     }

//     for (int ind1 = 1; ind1 <= n; ind1++)
//     {
//         for (int ind2 = 1; ind2 <= m; ind2++)
//         {
//             if (word1[ind1 - 1] == word2[ind2 - 1])
//             {
//                 dp[ind1][ind2] = 0 + dp[ind1 - 1][ind2 - 1];
//             }
//             else
//             {
//                 int insert = 1 + dp[ind1][ind2 - 1];
//                 int Delete = 1 + dp[ind1 - 1][ind2];
//                 int replace = 1 + dp[ind1 - 1][ind2 - 1];

//                 dp[ind1][ind2] = min(insert, min(Delete, replace));
//             }
//         }
//     }

//     cout << dp[n][m];

//     return 0;
// }

// SPACE OPTIMIZATION

#include <bits/stdc++.h>
using namespace std;

int main()
{

    string word1 = "sea", word2 = "eat";

    int n = word1.length(), m = word2.length();

    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    // for (int i = 0; i <= n; i++)
    // {
    //     curr[0] = i;         //We dont need this because we just want the previous column elemets
    // }
    for (int j = 0; j <= m; j++)
    {
        prev[j] = j;
    }

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        curr[0] = ind1;
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (word1[ind1 - 1] == word2[ind2 - 1])
            // 0 1 2 3
            // 1 1 2 3
            // 2 1 2 3
            // 3 2 1 2
            {
                curr[ind2] = 0 + prev[ind2 - 1];
            }
            else
            {
                int insert = 1 + curr[ind2 - 1];
                int Delete = 1 + prev[ind2];
                int replace = 1 + prev[ind2 - 1];

                curr[ind2] = min(insert, min(Delete, replace));
            }
        }
        prev = curr;
    }

    cout << prev[m];

    return 0;
}

// 0 1 2 3
// 1 1 2 3
// 2 1 2 3
// 3 2 1 2