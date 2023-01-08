// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

// APPROACH  --> Just reverse the string, and find the LCS. this will be its longest palindrome

// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb"

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
//     if (s1[ind1] == s2[ind2])
//     {
//         return 1 + f(ind1 - 1, ind2 - 1, s1, s2);
//     }
//     // NOT MATCH
//     return 0 + max(f(ind1 - 1, ind2, s1, s2), f(ind1, ind2 - 1, s1, s2));
// }

// int main()
// {

// string text1 = "bbbab";
// string text2 = text1;
// reverse(text2.begin(), text2.end());

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

//     string text1 = "bbbab";
//     string text2 = text1;
//     reverse(text2.begin(), text2.end());

//     int n = text1.length(), m = text2.length();

//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

//     cout << f(n - 1, m - 1, text1, text2, dp);

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string text1 = "cbbd";
// string text2 = text1;
// reverse(text2.begin(), text2.end());

//     int n = text1.length(), m = text2.length();

//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//     for (int i = 0; i <= n; i++)
//     {
//         dp[i][0] = 0;
//     }
//     for (int j = 0; j <= m; j++)
//     {
//         dp[0][j] = 0;
//     }
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

// SPACE OPTIMIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     string text1 = "cbbd";
//     string text2 = text1;
//     reverse(text2.begin(), text2.end());
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