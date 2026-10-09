#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> createGrid(int n, int m)
    {
        vector<string> ans;
        ans.reserve(n);
        ans.emplace_back(m, '.');
        if (n > 1)
        {
            string row;
            row.reserve(m);
            row.append(m - 1, '#');
            row.push_back('.');
            ans.insert(ans.end(), n - 1, row);
        }
        return ans;
    }
};