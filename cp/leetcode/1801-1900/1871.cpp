#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        int n = s.size();
        if (s[n - 1] != '0')
            return false;
        queue<pair<int, int>> q;
        q.push({minJump, maxJump});
        int i = 0;
        while (!q.empty())
        {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for (i = max(i, a); i <= b && i < n; i++)
            {
                if (s[i] == '0')
                {
                    if (i == n - 1)
                        return true;
                    q.push({i + minJump, i + maxJump});
                }
            }
        }
        return false;
    }
};