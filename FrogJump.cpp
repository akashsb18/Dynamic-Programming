// Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. At a time the frog can climb either one or two steps. A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.

// RECURSION
//  #include <bits/stdc++.h>
//  using namespace std;

// int f(int ind, vector<int> &v)
// {
//     if (ind == 0)
//     {
//         return 0;
//     }
//     int left = f(ind - 1, v) + abs(v[ind] - v[ind - 1]);
//     int right = INT_MAX;
//     if (ind > 1)
//     {
//         right = f(ind - 2, v) + abs(v[ind] - v[ind - 2]);
//     }
//     return min(left, right);
// }

// int main()
// {

//     vector<int> v = {30, 10, 60, 10, 60, 50};
//     int n = v.size();

//     cout << f(n - 1, v);

//     return 0;
// }

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, vector<int> &v, vector<int> &dp)
// {
//     if (ind == 0)
//     {
//         return 0;
//     }
//     if (dp[ind] != -1)
//     {
//         return dp[ind];
//     }
//     int left = f(ind - 1, v, dp) + abs(v[ind] - v[ind - 1]);
//     int right = INT_MAX;
//     if (ind > 1)
//     {
//         right = f(ind - 2, v, dp) + abs(v[ind] - v[ind - 2]);
//     }
//     return dp[ind] = min(left, right);
// }

// int main()
// {

//     vector<int> v = {30, 10, 60, 10, 60, 50};
//     int n = v.size();
//     vector<int> dp(n + 1, -1);
//     cout << f(n - 1, v, dp);

//     return 0;
// }

// TABULATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     vector<int> v = {30, 10, 60, 10, 60, 50};
//     int n = v.size();

//     vector<int> dp(n, -1);

//     dp[0] = 0;

//     for (int i = 1; i < n; i++)
//     {
//         int ls = dp[i - 1] + abs(v[i] - v[i - 1]);
//         int rs = INT_MAX;
//         if (i > 1)
//         {
//             rs = dp[i - 2] + abs(v[i - 2] - v[i]);
//         }

//         dp[i] = min(ls, rs);
//     }

//     cout << dp[n - 1];

//     return 0;
// }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// This is a follow-up question to “Frog Jump” discussed in the previous article. In the previous question, the frog was allowed to jump either one or two steps at a time. In this question, the frog is allowed to jump up to ‘K’ steps at a time. If K=4, the frog can jump 1,2,3, or 4 steps at every index.
// RECURSION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, vector<int> &v, int k)
// {
//     if (ind == 0)
//     {
//         return 0;
//     }
//     int MIN = INT_MAX;
//     for (int i = 1; i <= k; i++)
//     {
//         if ((ind - i) >= 0)
//         {
//             int steps = f(ind - i, v, k) + abs(v[ind] - v[ind - i]);
//             MIN = min(MIN, steps);
//         }
//     }

//     return MIN;
// }

// int main()
// {

//     vector<int> v = {30, 10, 60, 10, 60, 50};
//     int n = v.size();
//     int k = 2;
//     cout << f(n - 1, v, k);

//     return 0;
// }

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, vector<int> &v, int k, vector<int> &dp)
// {
//     if (ind == 0)
//     {
//         return 0;
//     }
//     if (dp[ind] != -1)
//     {
//         return dp[ind];
//     }
//     int MIN = INT_MAX;
//     for (int i = 1; i <= k; i++)
//     {
//         if ((ind - i) >= 0)
//         {
//             int steps = f(ind - i, v, k, dp) + abs(v[ind] - v[ind - i]);
//             MIN = min(MIN, steps);
//         }
//     }

//     return dp[ind] = MIN;
// }

// int main()
// {

//     vector<int> v = {30, 10, 60, 10, 60, 50};
//     int n = v.size();
//     vector<int> dp(n + 1, -1);
//     int k = 2;
//     cout << f(n - 1, v, k, dp);

//     return 0;
// }