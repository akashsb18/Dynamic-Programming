// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

// Example 1:

// Input: text1 = "abcde", text2 = "ace"
// Output: 3
// Explanation: The longest common subsequence is "ace" and its length is 3.
// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.

// RECURSION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind1, int ind2, string s1, string s2)
// {
//     if (ind1 < 0 or ind2 < 0)
//     {
//         return 0;
//     }
//     // MATCH
// if (s1[ind1] == s2[ind2])
// {
//     return 1 + f(ind1 - 1, ind2 - 1, s1, s2);
// }
// // NOT MATCH
// return 0 + max(f(ind1 - 1, ind2, s1, s2), f(ind1, ind2 - 1, s1, s2));
// }

// int main()
// {

//     string text1 = "abcde", text2 = "ace";

//     int n = text1.length(), m = text2.length();

//     cout << f(n - 1, m - 1, text1, text2);

//     return 0;
// }

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp)
// {
//     if (ind1 < 0 or ind2 < 0)
//     {
//         return 0;
//     }

//     if (dp[ind1][ind2] != -1)
//     {
//         return dp[ind1][ind2];
//     }
//     // MATCH
//     if (s1[ind1] == s2[ind2])
//     {
//         return 1 + f(ind1 - 1, ind2 - 1, s1, s2, dp);
//     }
//     // NOT MATCH
//     return dp[ind1][ind2] = 0 + max(f(ind1 - 1, ind2, s1, s2, dp), f(ind1, ind2 - 1, s1, s2, dp));
// }

// int main()
// {

// string text1 = "abcba", text2 = "abcbcba";

// int n = text1.length(), m = text2.length();

// vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

//     cout << f(n - 1, m - 1, text1, text2, dp);

//     return 0;
// }

// AFTER SHIFTING

// n --> n-1 therefore ind1 -> ind1-1 and ind2 --> ind2-1
// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp)
// {
//     if (ind1 == 0 or ind2 == 0)
//     {
//         return 0;
//     }

//     if (dp[ind1][ind2] != -1)
//     {
//         return dp[ind1][ind2];
//     }
//     // MATCH
//     if (s1[ind1 - 1] == s2[ind2 - 1])
//     {
//         return 1 + f(ind1 - 1, ind2 - 1, s1, s2, dp);
//     }
//     // NOT MATCH
//     return dp[ind1][ind2] = 0 + max(f(ind1 - 1, ind2, s1, s2, dp), f(ind1, ind2 - 1, s1, s2, dp));
// }

// int main()
// {

//     string text1 = "abcba", text2 = "abcbcba";

//     int n = text1.length(), m = text2.length();

//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

//     cout << f(n, m, text1, text2, dp);

//     return 0;
// }

// TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     string text1 = "abcba", text2 = "abcbcba";

//     int n = text1.length(), m = text2.length();

//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//     // HERE WE WILL DO SHIFTING BECAUSE WE DONT WANT T0 GIVE 0 indexing

//     for (int i = 0; i <= n; i++)
//     {
//         dp[i][0] = 0;
//     }
//     for (int j = 0; j <= m; j++)
//     {
//         dp[0][j] = 0;
//     }
//     n --> n-1 , 1 --> 0
//     for (int ind1 = 1; ind1 <= n; ind1++)
//     {
//         for (int ind2 = 1; ind2 <= m; ind2++)
//         {
//             if (text1[ind1 - 1] == text2[ind2 - 1])
//             {
//                 dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
//             }
//             // Have to include else because in recursion, it returns from this position
//             else
//             {
//                 dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
//             }
//         }
//     }

//     cout << dp[n][m];

//     return 0;
// }

// AFTER SHIFTING

// SPACE OPTIMIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     string text1 = "abcba", text2 = "abcbcba";

//     int n = text1.length(), m = text2.length();

//     vector<int> prev(m + 1, 0), curr(m + 1, 0);

//     for (int j = 0; j <= m; j++)
//     {
//         prev[j] = 0;
//     }

//     for (int ind1 = 1; ind1 <= n; ind1++)
//     {
//         for (int ind2 = 1; ind2 <= m; ind2++)
//         {
//             if (text1[ind1 - 1] == text2[ind2 - 1])
//             {
//                 curr[ind2] = 1 + prev[ind2 - 1];
//             }
//             else
//             {
//                 curr[ind2] = 0 + max(prev[ind2], curr[ind2 - 1]);
//             }
//         }
//         prev = curr;
//     }

//     cout << prev[m];

//     return 0;
// }