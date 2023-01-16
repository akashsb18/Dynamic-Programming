// Given a string s, partition s such that every
// substring
//  of the partition is a
// palindrome
// .

// Return the minimum cuts needed for a palindrome partitioning of s.

// Example 1:

// Input: s = "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
// Example 2:

// Input: s = "a"
// Output: 0

// Recursion

// #include <bits/stdc++.h>
// using namespace std;

// bool isPalindrome(string &S)
// {
//     string P = S;

//     reverse(P.begin(), P.end());

//     if (S == P)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// int f(int i, int n, string &s)
// {
//     string temp = "";

//     if (i == n)
//     {
//         return 0;
//     }

//     int mini = 1e9;
//     for (int j = i; j < n; j++)
//     {
//         temp += s[j];
//         if (isPalindrome(temp))
//         {
//             int cost = 1 + f(j + 1, n, s);
//             mini = min(mini, cost);
//         }
//     }
//     return mini;
// }

// int main()
// {

//     string s = "aab";

//     int n = s.length();

//     cout << f(0, n, s) - 1;

//     return 0;
// }

// Memoization

// #include <bits/stdc++.h>
// using namespace std;

// bool isPalindrome(string &S)
// {
//     string P = S;

//     reverse(P.begin(), P.end());

//     if (S == P)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// int f(int i, int n, string &s, vector<int> &dp)
// {
//     string temp = "";

//     if (i == n)
//     {
//         return 0;
//     }
//     if (dp[i] != -1)
//     {
//         return dp[i];
//     }

//     int mini = 1e9;
//     for (int j = i; j < n; j++)
//     {
// temp += s[j];
// if (isPalindrome(temp))
// {
//     int cost = 1 + f(j + 1, n, s, dp);
//     mini = min(mini, cost);
// }
//     }
//     return dp[i] = mini;
// }

// int main()
// {

// string s = "abaaaba";

// int n = s.length();

// vector<int> dp(n + 1, -1);

//     cout << f(0, n, s, dp) - 1;

//     // cout << isPalindrome(0, n - 1, s);

//     return 0;
// }

// Tabulation

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "abb";

    int n = s.length();

    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int mini = 1e9;

        for (int j = i; j < n; j++)
        {

            if (isPalindrome(i, j, s))
            {
                int cost = 1 + dp[j + 1];
                mini = min(mini, cost);
            }
        }
        dp[i] = mini;
    }
    cout << dp[0] - 1;

    return 0;
}
