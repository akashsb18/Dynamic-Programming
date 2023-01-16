// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// This question's code is taken from LARGEST RECTANGLE IN A HISTOGRAM CODE

#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int maxA = 0;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() and (i == n or heights[st.top()] >= heights[i]))
        {
            int height = heights[st.top()];
            st.pop();
            int width;
            if (st.empty())
            {
                width = i;
            }
            else
            {
                width = i - st.top() - 1;
            }
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }

    return maxA;
}

int main()
{

    vector<vector<int>> v = {{1, 0, 1, 0, 0}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}};
    int n = v.size(), m = v[0].size();
    int maxArea = 0, ans = 0;
    vector<int> height(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 1)
            {
                height[j]++;
            }
        }
        int maxArea = largestRectangleArea(height);
        ans = max(ans, maxArea);
    }

    cout << ans;

    return 0;
}