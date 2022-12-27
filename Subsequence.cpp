// #include <bits/stdc++.h>
// using namespace std;

// void f(int ind, vector<int> &v, vector<int> &empt)
// {
//     if (ind >= v.size())
//     {
//         for (auto it : empt)
//         {
//             cout << it << " ";
//         }
//         cout << endl;
//         return;
//     }
//     empt.push_back(v[ind]);
//     f(ind + 1, v, empt);
//     empt.pop_back();
//     f(ind + 1, v, empt);
// }

// int main()
// {

//     vector<int> v = {3, 2, 1, 2, 5};
//     int n = v.size();

//     vector<int> empt;

//     f(0, v, empt);

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// void f(int ind, string &v, vector<char> &empt, int &c)
// {

//     if (ind >= v.size())
//     {
//         for (auto it : empt)
//         {
//             cout << it << " ";
//         }
//         c++;
//         cout << endl;
//         return;
//     }
//     empt.push_back(v[ind]);
//     f(ind + 1, v, empt, c);
//     empt.pop_back();
//     f(ind + 1, v, empt, c);
// }

// int main()
// {

//     string v = "aaa";
//     int n = v.length();
//     int c = 0;
//     vector<char> empt;

//     f(0, v, empt, c);

//     cout << c - 1;

//     return 0;
// }

// SUBSEQUENCE WITH SUM EQUAL TO A GIVEN VALUE

#include <bits/stdc++.h>
using namespace std;

void f(int ind, vector<int> v, int s, int A[], int n, int sum)
{
    if (ind == n)
    {
        if (s == sum)
        {
            for (auto it : v)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    v.push_back(A[ind]);
    s += A[ind];
    f(ind + 1, v, s, A, n, sum);

    v.pop_back();
    s -= A[ind];
    f(ind + 1, v, s, A, n, sum);
}

int main()
{

    int arr[] = {1, 2, 1};
    int sum = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v;
    f(0, v, 0, arr, n, sum);

    return 0;
}