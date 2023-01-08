#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};

    vector<int> temp;

    temp.push_back(v[0]);

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > temp.back())
        {
            temp.push_back(v[i]);
        }
        else
        {
            auto ind = lower_bound(temp.begin(), temp.end(), v[i]);
            temp[ind - temp.begin()] = v[i];
        }
    }

        cout << temp.size();

    return 0;
}