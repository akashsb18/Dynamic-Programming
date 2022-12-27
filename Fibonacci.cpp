// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int fib(vector<int> &dp, int n)
// {
//     if (n == 0 or n == 1)
//     {
//         return n;
//     }
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     return dp[n] = fib(dp, n - 1) + fib(dp, n - 2);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> dp(n + 1, -1);

//     cout << fib(dp, n);

//     return 0;
// }

// OPTIMISED TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int n;
//     cin >> n;
//     int prev = 1, prev2 = 0;

//     for (int i = 2; i <= n; i++)
//     {
//         int curri = prev + prev2;
//         prev2 = prev;
//         prev = curri;
//     }

//     cout << prev << endl;

//     return 0;
// }
