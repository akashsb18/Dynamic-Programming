// You are given an expression ‘EXP’ in the form of a string where operands will be : (TRUE and FALSE) and operators will be : (AND, OR, XOR). Now you have to find the number of ways we can parenthesize the expression such that it will evaluate to TRUE.

// Note :

// ‘T’ will represent the operand TRUE.
// ‘F’ will represent the operand FALSE.
// ‘|’ will represent the operator OR.
// ‘&’ will represent the operator AND.
// ‘^’ will represent the operator XOR.
// For example :

//  Input:
//  'EXP’ = T|T & F
//  There are total 2  ways to parenthesize this expression:
//  (i) (T | T) & (F) = F
//  (ii) (T) | (T & F) = T
//  Out of 2 ways, one will result in True, so we will return 1.

//  Output :
//  1

// Intution
// After every two steps, there is an operand
// We can do partition on the operand

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int f(int i, int j, int isTrue, string &s, vector<vector<int>> &dp)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        if (isTrue)
        {
            return s[i] == 'T';
        }
        else
        {
            return s[i] == 'F';
        }
    }
    ll costs = 0;

    for (int ind = i + 1; ind <= j - 1; ind++)
    {
        ll lt = f(i, ind - 1, 1, s, dp);
        ll lf = f(i, ind - 1, 0, s, dp);
        ll rt = f(ind + 1, j, 1, s, dp);
        ll rf = f(ind + 1, j, 0, s, dp);
        if (s[ind] == '&')
        {
            if (isTrue)
            {
                costs += (lt * rt) % mod;
            }
            else
            {
                costs += ((lt * rf) % mod + (lf * rt) % mod + (rf * lf) % mod) % mod;
            }
        }
        else if (s[ind] == '|')
        {
            if (isTrue)
            {
                costs += ((lt * rt) % mod + (lt * rf) % mod + (lf * rt) % mod) % mod;
            }
            else
            {
                costs += (lf * rf) % mod;
            }
        }
        else if (s[ind] == '^')
        {
            if (isTrue)
            {
                costs += ((lt * rf) % mod + (lf * rt) % mod) % mod;
            }
            else
            {
                costs += ((lf * rf) % mod + (lt * rt) % mod) % mod;
            }
        }
    }

    return costs;
}

int main()
{

    string exp = "T|T&F";

    int n = exp.length();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    cout << f(0, n - 1, 1, exp, dp);

    return 0;
}