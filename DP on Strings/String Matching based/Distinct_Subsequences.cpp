// Given two strings s and t, return the number of distinct subsequences of s which equals t.

//                                       The test cases are generated so that the answer fits on a 32 -
//                                       bit signed integer.

//                                       Example 1 :

//     Input : s = "rabbbit",
//             t = "rabbit" Output : 3 Explanation : As shown below, there are 3 ways you can generate "rabbit" from s.rabbbit rabbbit rabbbit

// We need two parameters, i and j --> f(n-1,m-1) --> Number of distinct subsequence of t(0....j) in s(0....i)

// If all characteres of t match then i'll return 1 i.e j<0

// t kitne tariko se s mai present hai, wo dhundna hai

// RECURSION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind1, int ind2, string &s, string &t)
// {

//     if (ind2 < 0)
//     {
//         return 1;
//     }
//     if (ind1 < 0)
//     {
//         return 0;
//     }

//     if (s[ind1] == t[ind2]) // If match
//     {
//         return f(ind1 - 1, ind2 - 1, s, t) + f(ind1 - 1, ind2, s, t);
//     }
//     return f(ind1 - 1, ind2, s, t);
// }

// int main()
// {

//     string s = "rabbbit", t = "rabbit";

//     int n = s.length(), m = t.length();

//     cout << f(n - 1, m - 1, s, t);

//     return 0;
// }

// TC --> O(2^(n+m)) SC --> O(n+m)

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp)
// {

//     if (ind2 < 0)
//     {
//         return 1;
//     }
//     if (ind1 < 0)
//     {
//         return 0;
//     }

//     if (dp[ind1][ind2] != -1)
//     {
//         return dp[ind1][ind2];
//     }

//     if (s[ind1] == t[ind2]) // If match
//     {
//         return f(ind1 - 1, ind2 - 1, s, t, dp) + f(ind1 - 1, ind2, s, t, dp);
//     }
//     return dp[ind1][ind2] = f(ind1 - 1, ind2, s, t, dp);
// }

// int main()
// {

//     string s = "rabbbit", t = "rabbit";

//     int n = s.length(), m = t.length();

//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

//     cout << f(n - 1, m - 1, s, t, dp);

//     return 0;
// }

// TC --> O(nxm) , SC --> O(nxm)+O(n+m)

// Memoization -- after shifting

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp)
// {

//     if (ind2 == 0)
//     {
//         return 1;
//     }
//     if (ind1 == 0)
//     {
//         return 0;
//     }

//     if (dp[ind1][ind2] != -1)
//     {
//         return dp[ind1][ind2];
//     }

// if (s[ind1 - 1] == t[ind2 - 1]) // If match
// {
//     return f(ind1 - 1, ind2 - 1, s, t, dp) + f(ind1 - 1, ind2, s, t, dp);
// }
// return dp[ind1][ind2] = f(ind1 - 1, ind2, s, t, dp);
// }

// int main()
// {

// string s = "rabbbit", t = "rabbit";

// int n = s.length(), m = t.length();

// vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

//     cout << f(n, m, s, t, dp);

//     return 0;
// }

// TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     string s = "rabbbit", t = "rabbit";

//     int n = s.length(), m = t.length();

//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//     for (int i = 0; i <= n; i++)
//     {
//         dp[i][0] = 1;
//     }
//     for (int j = 1; j <= m; j++) // Here j will start from 1 because for j=0, we have already written the above code
//     {
//         dp[0][j] = 0;            // You dont need to write these as well, as we have initialised the vector to be zero already
//     }

//     for (int ind1 = 1; ind1 <= n; ind1++)
//     {
//         for (int ind2 = 1; ind2 <= m; ind2++)
//         {
//             if (s[ind1 - 1] == t[ind2 - 1])
//             {
//                 dp[ind1][ind2] = dp[ind1 - 1][ind2 - 1] + dp[ind1 - 1][ind2];
//             }
//             else
//             {
//                 dp[ind1][ind2] = dp[ind1 - 1][ind2];
//             }
//         }
//     }

//     // for (int i = 0; i <= n; i++)
//     // {
//     //     for (int j = 0; j <= m; j++)
//     //     {
//     //         cout << dp[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }

//     cout << dp[n][m];

//     return 0;
// }

// SPACE OPTIMIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     string s = "rabbbit", t = "rabbit";

//     int n = s.length(), m = t.length();

//     vector<int> prev(m + 1, 0), curr(m + 1, 0);

//     prev[0] = curr[0] = 1;

//         for (int ind1 = 1; ind1 <= n; ind1++)
//     {
//         for (int ind2 = 1; ind2 <= m; ind2++)
//         {
//             if (s[ind1 - 1] == t[ind2 - 1])
//             {
//                 curr[ind2] = prev[ind2 - 1] + prev[ind2];
//             }
//             else
//             {
//                 curr[ind2] = prev[ind2];
//             }
//         }
//         prev = curr;
//     }

//     cout << prev[m];

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s = "rabbbit", t = "rabbit";

    int n = s.length(), m = t.length();

    vector<int> prev(m + 1, 0);

    prev[0] = 1;

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = m; ind2 >= 0; ind2--)
        {
            if (s[ind1 - 1] == t[ind2 - 1])
            {
                prev[ind2] = prev[ind2 - 1] + prev[ind2];
            }
            // else
            // {
            //     prev[ind2] = prev[ind2]; //Dont need to write
            // }
        }
        }

    cout << prev[m];

    return 0;
}