// Given a string s.In one step you can insert any character at any index of the string.

//     Return the minimum number of steps to make s palindrome.

//     A Palindrome String is one that reads the same backward as well as forward.

//     Example 2:

// Input: s = "mbadm"
// Output: 2
// Explanation: String can be "mbdadbm" or "mdbabdm".

// Approach

// ** Keep the longest palindrome subsequence portion intact

// You will get the answer by hit and trial.
// The answer will be ---- Length of string - longest commmon palindromic subsequence

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp)
// {

//     if (ind1 == 0 or ind2 == 0)
//     {
//         return 0;
//     }
//     if (dp[ind1][ind2] != -1)
//     {
//         return dp[ind1][ind2];
//     }

//     if (s1[ind1 - 1] == s2[ind2 - 1])
//     {
//         return 1 + f(ind1 - 1, ind2 - 1, s1, s2, dp);
//     }
//     return dp[ind1][ind2] = 0 + max(f(ind1 - 1, ind2, s1, s2, dp), f(ind1, ind2 - 1, s1, s2, dp));
// }

// int main()
// {

//     string s = "leetcode";
//     string t = s;

//     reverse(t.begin(), t.end());

//     int n = s.length(), m = t.length();

//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

//     int lcps = f(n, m, s, t, dp);

//     cout << n - lcps;

//     return 0;
// // }
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     string text1 = "leetcode";
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

//     int temp = prev[m];

//     cout << n - temp;

//     return 0;
// }