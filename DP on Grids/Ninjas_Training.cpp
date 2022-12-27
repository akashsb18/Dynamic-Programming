// Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

// You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

// Sample Input 1:
// 2
// 3
// 1 2 5
// 3 1 1
// 3 3 3
// 3
// 10 40 70
// 20 50 80
// 30 60 90

// Sample Output 1:
// 11
// 210

// RECURSION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int day, int last, vector<vector<int>> &v)
// {

//     if (day == 0)
//     {
//         int maxi = 0;
//         for (int task = 0; task < 3; task++)
//         {
//             if (task != last)
//             {
//                 maxi = max(maxi, v[0][task]);
//             }
//         }
//         return maxi;
//     }
//     int maxi = 0;
//     for (int task = 0; task < 3; task++)
//     {
//         if (task != last)
//         {
//             int point = v[day][task] + f(day - 1, task, v);
//             maxi = max(maxi, point);
//         }
//     }

//     return maxi;
// }

// int main()
// {

//     vector<vector<int>> v = {{1, 2, 5},
//                              {3, 1, 1},
//                              {3, 3, 3}};

//     cout << f(v.size() - 1, 3, v);

//     return 0;
// }

// MEMOIZATION

// #include <bits/stdc++.h>
// using namespace std;

// int f(int day, int last, vector<vector<int>> &v, vector<vector<int>> &dp)
// {

//     if (day == 0)
//     {
//         int maxi = 0;
//         for (int task = 0; task < 3; task++)
//         {
//             if (task != last)
//             {
//                 maxi = max(maxi, v[0][task]);
//             }
//         }
//         return maxi;
//     }
//     if (dp[day][last] != -1)
//     {
//         return dp[day][last];
//     }
//     int maxi = 0;
//     for (int task = 0; task < 3; task++)
//     {
//         if (task != last)
//         {
//             int point = v[day][task] + f(day - 1, task, v, dp);
//             maxi = max(maxi, point);
//         }
//     }

//     return dp[day][last] = maxi;
// }

// int main()
// {

//     vector<vector<int>> v = {{1, 2, 5},
//                              {3, 1, 1},
//                              {3, 3, 3}};
//     vector<vector<int>> dp(v.size(), vector<int>(4, -1));
//     cout << f(v.size() - 1, 3, v, dp);

//     return 0;
// }

// TABULATION

#include <bits/stdc++.h>
using namespace std;

int f(int day, int last, vector<vector<int>> &v, vector<vector<int>> &dp)
{

    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, v[0][task]);
            }
        }
        return maxi;
    }
    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }
    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = v[day][task] + f(day - 1, task, v, dp);
            maxi = max(maxi, point);
        }
    }

    return dp[day][last] = maxi;
}

int main()
{

    vector<vector<int>> v = {{1, 2, 5},
                             {3, 1, 1},
                             {3, 3, 3}};
    vector<vector<int>> dp(v.size(), vector<int>(4, -1));

    dp[0][0] = max(v[0][1], v[0][2]);
    dp[0][1] = max(v[0][0], v[0][2]);
    dp[0][2] = max(v[0][0], v[0][1]);
    dp[0][3] = max(v[0][1], max(v[0][2], v[0][3]));

    for (int day = 0; day < v.size(); day++)
    {

        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = v[day][task] + dp[day - 1][task];
                    maxi = max(maxi, point);
                }
            }
            dp[day][last] = maxi;
        }
    }

    cout << dp[v.size() - 1][3];

    return 0;
}