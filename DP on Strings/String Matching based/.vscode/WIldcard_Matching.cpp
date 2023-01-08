// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".

// Example 2:

// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.

// Approach --> The main problem here is with star, rest can me made with direct string matching,for star we have to check all possible ways

// RECURSION

// class Solution {
// public:
//     bool f(int ind1, int ind2, string &s, string &p)
// {

//         if (ind1 < 0 and ind2 < 0)
//         {
//             return true;
//         }
//         if (ind1 < 0 and ind2 >= 0)
//         {
//             return false;
//         }
//         if (ind2 < 0 and ind1 >= 0)
//         {
//             for (int i = 0; i <= ind1; i++)
//             {
//                 if (s[i] != '*')
//                 {
//                     return false;
//                 }
//             }
//             return true;
//         }

//         if (s[ind1] == p[ind2] or s[ind1] == '?')
//         {
//             return f(ind1 - 1, ind2 - 1, s, p);
//         }
//         if (s[ind1] == '*')
//         {
//             bool notTake = f(ind1 - 1, ind2, s, p);
//             bool take = f(ind1, ind2 - 1, s, p);

//             return notTake or take;
//         }
//         return false;
// }
//     bool isMatch(string p, string s) {
//         int n = s.length(), m = p.length();

//         return f(n - 1, m - 1, s, p);
//     }
// };

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// bool f(int ind1, int ind2, string &s, string &p, vector<vector<int>> &dp)
// {

//     if (ind1 < 0 and ind2 < 0)
//     {
//         return true;
//     }
//     if (ind1 < 0 and ind2 >= 0)
//     {
//         return false;
//     }
//     if (ind2 < 0 and ind1 >= 0)
//     {
//         for (int i = 0; i <= ind1; i++)
//         {
//             if (s[i] != '*')
//             {
//                 return false;
//             }
//         }
//         return true;
//     }

//     if (dp[ind1][ind2] != -1)
//     {
//         return dp[ind1][ind2];
//     }

//     if (s[ind1] == p[ind2] or s[ind1] == '?')
//     {
//         return dp[ind1][ind2] = f(ind1 - 1, ind2 - 1, s, p, dp);
//     }
//     if (s[ind1] == '*')
//     {
//         bool notTake = f(ind1 - 1, ind2, s, p, dp);
//         bool take = f(ind1, ind2 - 1, s, p, dp);

//         return dp[ind1][ind2] = notTake or take;
//     }
//     return dp[ind1][ind2] = false;
// }

// int main()
// {

//     // String s should contain al the ? or * , p should not contain all these stuffs

// string s = "?a", p = "ca";

// int n = s.length(), m = p.length();

// vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

//     cout << f(n - 1, m - 1, s, p, dp);

//     return 0;
// }

// TC --> O(n x m)  SC --> O(n x m) + O(n + m)

// After Shifting

// #include <bits/stdc++.h>
// using namespace std;

// bool f(int ind1, int ind2, string &s, string &p, vector<vector<int>> &dp)
// {

//     if (ind1 == 0 and ind2 == 0)
//     {
//         return true;
//     }
//     if (ind1 == 0 and ind2 > 0)
//     {
//         return false;
//     }
//     if (ind2 == 0 and ind1 > 0)
//     {
// for (int i = 1; i <= ind1; i++)
// {
//     if (s[i - 1] != '*')
//     {
//         return false;
//     }
// }
//         return true;
//     }

//     if (dp[ind1][ind2] != -1)
//     {
//         return dp[ind1][ind2];
//     }

// if (s[ind1 - 1] == p[ind2 - 1] or s[ind1 - 1] == '?')
// {
//     return dp[ind1][ind2] = f(ind1 - 1, ind2 - 1, s, p, dp);
// }
// if (s[ind1 - 1] == '*')
// {
//     bool notTake = f(ind1 - 1, ind2, s, p, dp);
//     bool take = f(ind1, ind2 - 1, s, p, dp);

//     return dp[ind1][ind2] = notTake or take;
// }
// return dp[ind1][ind2] = false;
// }

// int main()
// {

//     // String s should contain al the ? or * , p should not contain all these stuffs

//     string s = "tyrft*", p = "ertyuca";

//     int n = s.length(), m = p.length();

//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

//     cout << f(n, m, s, p, dp);

//     return 0;
// }

// TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     string s = "*", p = "ca";

//     int n = s.length(), m = p.length();

//     vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

//     dp[0][0] = true;

//     for (int j = 1; j <= m; j++)
//     {
//         dp[0][j] = false;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         bool flag = true;
//         for (int ii = 1; ii <= i; ii++)
//         {
//             if (s[ii - 1] != '*')
//             {
//                 flag = false;
//                 break;
//             }
//         }
//         dp[i][0] = flag;
//     }

//     for (int ind1 = 1; ind1 <= n; ind1++)
//     {
//         for (int ind2 = 1; ind2 <= m; ind2++)
//         {
//             if (s[ind1 - 1] == p[ind2 - 1] or s[ind1 - 1] == '?')
//             {
//                 dp[ind1][ind2] = dp[ind1 - 1][ind2 - 1];
//             }
//             else if (s[ind1 - 1] == '*')
//             {
//                 bool notTake = dp[ind1 - 1][ind2];
//                 bool take = dp[ind1][ind2 - 1];

//                 dp[ind1][ind2] = notTake or take;
//             }
//             else
//             {
//                 dp[ind1][ind2] = false;
//             }
//         }
//     }

//     cout << dp[n][m];

//     return 0;
// }

// TC --> O(n x m) and Sc --> O(n x m)

// Space Opitmization

#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s = "*a*b", p = " adceb ";

    int n = s.length(), m = p.length();
    // prev --> 0th row            //curr --> 1st row
    vector<bool> prev(m + 1, false), curr(m + 1, false);

    prev[0] = true;

    for (int j = 1; j <= m; j++)
    {
        prev[j] = false;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     bool flag = true;
    //     for (int ii = 1; ii <= i; ii++)
    //     {
    //         if (s[ii - 1] != '*')
    //         {
    //             flag = false;
    //             break;
    //         }
    //     }

    //     curr[0] = flag;
    // }

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        bool flag = true;
        for (int ii = 1; ii <= ind1; ii++)
        {
            if (s[ii - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        // for every row you are assigning the 0th column's value
        curr[0] = flag;
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s[ind1 - 1] == p[ind2 - 1] or s[ind1 - 1] == '?')
            {
                curr[ind2] = prev[ind2 - 1];
            }
            else if (s[ind1 - 1] == '*')
            {
                bool notTake = prev[ind2];
                bool take = curr[ind2 - 1];

                curr[ind2] = notTake or take;
            }
            else
            {
                curr[ind2] = false;
            }
        }
        prev = curr;
    }

    cout << prev[m];

    return 0;
}