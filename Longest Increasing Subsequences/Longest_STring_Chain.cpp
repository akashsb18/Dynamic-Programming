// You are given an array of words where each word consists of lowercase English letters.

// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

// Return the length of the longest possible word chain with words chosen from the given list of words.

// Example 1:

// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
// Example 2:

// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

#include <bits/stdc++.h>
using namespace std;

// bool Comp(string &s, string &t)
// {
//     if (s.length() != t.length() + 1)
//     {
//         return false;
//     }
//     int i = 0, j = 0;
//     while (i < s.length())
//     {
//         if (j < t.length() and s[i] == s[j])
//         {
//             i++;
//             j++;
//         }
//         else
//         {
//             i++;
//         }
//     }
//     if (i == s.length() and j == t.length())
//     {
//         return true;
//     }
//     return false;
// }

bool Comp(string &s1, string &s2)
{
    if (s1.size() != s2.size() + 1)
        return false;
    int first = 0;
    int second = 0;
    while (first < s1.size())
    {
        if (s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else
            first++;
    }
    if (first == s1.size() && second == s2.size())
        return true;
    return false;
}

bool comparator(string &s, string &t)
{
    return s.length() < t.length();
}

int main()
{

    // vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<string> nums = {"a", "b", "ba", "bca", "bda", "bdca"};

    sort(nums.begin(), nums.end(), comparator);

    // for (auto it : nums)
    // {
    //     cout << it << " ";
    // }
    // sort in terms of length of string becasue we wanted subset not subsequence

    int n = nums.size();

    vector<int> dp(n, 1);

    int maxi = -1e9;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (Comp(nums[i], nums[j]) and 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
        }
    }

    cout << maxi;

    return 0;
}