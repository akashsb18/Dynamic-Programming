// Given an integer array nums, return the length of the longest strictly increasing
// subsequence
// .

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

// Need to take the store the value of previous because prev allows to store whether we can take element into consideration or not

// f(ind,prev_ind)   -->  f(0,-1) length of longest increasing subsequence starting from index zero with no previous element

// from given example we can say that either 10 come and be my part or dont be my part

// RECURSION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, int prev_ind, vector<int> &v)
// {

//     if (ind == v.size())
//     {
//         return 0;
//     }

//     int notTake = 0 + f(ind + 1, prev_ind, v);
//     int take = -1e9;
//     if (prev_ind == -1 or v[ind] > v[prev_ind])
//     {
//         take = 1 + f(ind + 1, ind, v);
//     }

//     return max(notTake, take);
// }

// int main()
// {

//     vector<int> nums = {7, 7, 7, 7, 7, 7, 7};

//     int n = nums.size();

//     cout << f(0, -1, nums);

//     return 0;
// }

// TC-- > O(2 ^ n) SC-- > O(n)

//                            MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, int prev_ind, vector<int> &v, vector<vector<int>> &dp)
// {

//     if (ind == v.size())
//     {
//         return 0;
//     }

//     if (dp[ind][prev_ind + 1] != -1)
//     {
//         return dp[ind][prev_ind + 1];
//     }

// int notTake = 0 + f(ind + 1, prev_ind, v, dp);
// int take = -1e9;
// if (prev_ind == -1 or v[ind] > v[prev_ind])
// {
//     take = 1 + f(ind + 1, ind, v, dp);
// }

//     return dp[ind][prev_ind + 1] = max(notTake, take);
// }

// int main()
// {

// vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

// int n = nums.size();

// vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

//     cout << f(0, -1, nums, dp);

//     return 0;
// }

// TC --> O(n x n) SC --> O(n) + O(n x n)

//  TABULATIOIN

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

//     int n = nums.size();

//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

//     for (int ind = n - 1; ind >= 0; ind--)
//     {
//         for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
//         {
//             int notTake = 0 + dp[ind + 1][prev_ind + 1];
//             int take = -1e9;
//             if (prev_ind == -1 or nums[ind] > nums[prev_ind])
//             {
//                 take = 1 + dp[ind + 1][ind + 1];
//             }

//             dp[ind][prev_ind + 1] = max(notTake, take);
//         }
//     }

//     cout << dp[0][-1 + 1];

//     return 0;
// }

// SPACE OPTIMIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

// vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

// int n = nums.size();

//     vector<int> next(n + 1, 0), curr(n + 1, 0);

//     for (int ind = n - 1; ind >= 0; ind--)
//     {
//         for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
//         {
//             int notTake = 0 + next[prev_ind + 1];
//             int take = -1e9;
//             if (prev_ind == -1 or nums[ind] > nums[prev_ind])
//             {
//                 take = 1 + next[ind + 1];
//             }

//             curr[prev_ind + 1] = max(notTake, take);
//         }
//         next = curr;
//     }

//     cout << curr[-1 + 1];

//     return 0;
// }

//  TC --> O(n x n) , SC --> O(n)

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

// vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

// int n = nums.size();

// vector<int> dp(n, 1);

// for (int i = 0; i < n; i++)
// {
//     for (int j = 0; j < i; j++)
//     {
//         if (nums[j] < nums[i])
//         {
//             dp[i] = max(1 + dp[j], dp[i]);
//         }
//     }
// }

// int ans = *max_element(dp.begin(), dp.end());

// cout << ans;

//     return 0;
// }

// TC --> O(n x n),  SC --> O(n)