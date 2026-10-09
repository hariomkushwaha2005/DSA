#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(string s, string t)
    {
        int n = s.size();
        if (n == 1)
        {
            if (s[0] == t[0])
                return 0;
            return s[0] == '0' ? 1 : -1;
        }
        int ops = 0;
        for (int i = n - 1; i > 0; --i)
        {
            if (s[i] != t[i])
            {
                if (s[i] == '1')
                {
                    if (s[i - 1] == '0')
                    {
                        ops += 2;
                    }
                    else
                    {
                        ops++;
                        s[i - 1] = '0';
                    }
                }
                else
                    ops++;
            }
        }
        if (s[0] != t[0])
        {
            if (s[0] == '0')
                ops++;
            else
            {
                ops += 2;
            }
        }
        return ops;
    }
};