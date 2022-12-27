// Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.

// Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, ‘C’ - 1) in the grid. Each of them can move from their current cell to the cells just below them. When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will become zero. If both stay in the same cell, only one of them will pick the chocolates in it.

// If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1). They will always stay inside the ‘GRID’.

// Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.

// Solution

// We have a fixed starting position. i.e ALice in top-left position and Bob in top right position

//(1) Express everything in terms of (i1,j1) and (i2,j2);

// We will start from (0,0) then go to m-1,n-1 as starting point is given i.e f(0,0,0,m-1) Alice and bob

// Base Case :- 1) Destination base case
//              2) Out of bound base Case.

// Always write the out of bound case first.

// #include <bits/stdc++.h>
// using namespace std;

// int f(int i, int j1, int j2, vector<vector<int>> &v) // Changes in row for both Alice and Bob will be same so,i1=i2=i
// {
//     if (j1 < 0 or j1 >= v[0].size() or j2 < 0 or j2 >= v[0].size())
//     {
//         return -1e8;
//     }
//     if (i == v.size() - 1)
//     { // When they reache the last row
//         if (j1 == j2)
//         {
//             return v[i][j1];
//         }
//         else
//         {
//             return v[i][j1] + v[i][j2];
//         }
//     }
//     // We will have 9 combos in every step
//     int maxi = -1e8;
//     for (int dj1 = -1; dj1 <= 1; dj1++)
//     {
//         for (int dj2 = -1; dj2 <= 1; dj2++)
//         {
//             int value = 0;
//             if (j1 == j2)
//             {
//                 value = v[i][j1];
//             }
//             else
//             {
//                 return v[i][j1] + v[i][j2];
//             }
//             value += f(i + 1, j1 + dj1, j2 + dj2, v);
//             maxi = max(maxi, value);
//         }
//     }

//     return maxi;
// }

// int main()
// {

//     vector<vector<int>> v = {{2, 3, 1, 2},
//                              {3, 4, 2, 2},
//                              {5, 6, 3, 5}};

//     int m = v[0].size();
//     int n = v.size();

//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

//     cout << f(0, 0, m - 1, v);

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j1, int j2, vector<vector<int>> &v, vector<vector<vector<int>>> dp) // Changes in row for both Alice and Bob will be same so,i1=i2=i
{
    if (j1 < 0 or j1 >= v[0].size() or j2 < 0 or j2 >= v[0].size())
    {
        return -1e8;
    }
    if (i == v.size() - 1)
    { // When they reache the last row
        if (j1 == j2)
        {
            return v[i][j1];
        }
        else
        {
            return v[i][j1] + v[i][j2];
        }
    }

    if (dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }
    // We will have 9 combos in every step
    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
            {
                value = v[i][j1];
            }
            else
            {
                return v[i][j1] + v[i][j2];
            }
            value += f(i + 1, j1 + dj1, j2 + dj2, v, dp);
            maxi = max(maxi, value);
        }
    }

    return dp[i][j1][j2] = maxi;
}

int main()
{

    vector<vector<int>> v = {{2, 3, 1, 2},
                             {3, 4, 2, 2},
                             {5, 6, 3, 5}};

    int m = v[0].size();
    int n = v.size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    cout << f(0, 0, m - 1, v, dp);

    return 0;
}