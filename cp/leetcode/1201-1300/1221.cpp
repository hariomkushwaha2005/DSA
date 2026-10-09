#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int balancedStringSplit(const string &s)
    {
        int l = 0, cnt = 0;
        for (char c : s)
        {
            if (c == 'L')
                ++l;
            else
                --l;

            if (l == 0)
                ++cnt;
        }
        return cnt;
    }
};