#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        vector<int> v(256, -1);
        int l = 0, len = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[s[i]] != -1)
            {
                l = max(l, v[s[i]] + 1);
            }
            len = max(i - l + 1, len);
            v[s[i]] = i;
        }
        return len;
    }
};