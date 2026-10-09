#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        int n = s.size();
        if (s.size() != goal.size())
            return false;
        int arr[26] = {0};
        int cnt = 0, l = 0, r = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != goal[i])
            {
                cnt++;
                if (cnt == 1)
                    l = i;
                else if (cnt == 2)
                    r = i;
                else
                    return false;
            }
            arr[s[i] - 'a']++;
        }
        if (cnt == 2 && s[l] == goal[r] && s[r] == goal[l])
            return true;
        if (cnt == 0)
        {
            for (auto &x : arr)
            {
                if (x > 1)
                    return true;
            }
        }
        return false;
    }
};