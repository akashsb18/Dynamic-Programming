// Given an array, ‘Arr’ of length ‘n’, find the longest bitonic subsequence.

// Problem Statement:

// Let us first understand what a bitonic subsequence means.

// A bitonic subsequence is a subsequence of an array in which the elements can be any of these three:

// Similarly, a subsequence having the elements in either increasing or decreasing order only also counts as a bitonic subsequence. For example:

// 5
// 1 2 1 2 1
// 5
// 1 2 1 3 4
// Sample Output 1:
// 4
// 4
// Explanation For Sample Input 1:
// The longest bitonic sequence for the first test case will be [1, 2, 2, 1].
// The longest bitonic sequence for the second test case will be [1, 2, 3, 4]

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> temp = nums;
    reverse(temp.begin(), temp.end());

    int n = nums.size();

    vector<int> dp1(n, 1), dp2(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp1[i] = max(1 + dp1[j], dp1[i]);
            }
        }
    }

    // for (auto it : dp1)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (temp[j] < temp[i])
            {
                dp2[i] = max(1 + dp2[j], dp2[i]);
            }
        }
    }

    reverse(dp2.begin(), dp2.end());

    vector<int> ans;
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(dp1[i] + dp2[i] - 1);
        if (ans[i] > maxi)
        {
            maxi = ans[i];
        }
    }

    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    cout << maxi;

    return 0;
}
