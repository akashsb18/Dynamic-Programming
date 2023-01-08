// Given a set of distinct positive integers nums, return the largest subset answer such that every pair(answer[i], answer[j]) of elements in this subset satisfies :

//     answer[i] %
//     answer[j] == 0,
//     or
//         answer[j] % answer[i] == 0 If there are multiple solutions,
//     return any of them.

//            Example 1 :

//     Input : nums = [ 1, 2, 3 ] Output : [ 1, 2 ] Explanation : [ 1, 3 ] is also accepted.Example 2 :

//     Input : nums = [ 1, 2, 4, 8 ] Output : [ 1, 2, 4, 8 ]

// Similar to printing LIS

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    // 2,3,5,7,9,10,18,101

    int n = nums.size();

    vector<int> dp(n, 1), hash(n, 0);

    int lastIndex = 0;

    int maxi = -1e9;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0 and 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
                hash[i] = j;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    // cout << lastIndex;

    int ans[maxi];
    ans[0] = nums[lastIndex];
    int ind = 1;
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        ans[ind++] = nums[lastIndex];
    }

    reverse(ans, ans + maxi);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}