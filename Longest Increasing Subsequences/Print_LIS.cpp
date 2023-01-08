#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    int n = nums.size();

    vector<int> dp(n, 1), hash(n, 0);

    int lastIndex = 0;

    int maxi = -1e9;

    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] and 1 + dp[j] > dp[i])
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