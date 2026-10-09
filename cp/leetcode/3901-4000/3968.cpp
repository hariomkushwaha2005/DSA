#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(const string &moves)
    {
        const char *ptr = moves.data();
        const char *end = ptr + moves.length();
        int x = 0, y = 0, dash = 0;
        while (ptr < end)
        {
            switch (*ptr)
            {
            case 'L':
                ++x;
                break;
            case 'R':
                --x;
                break;
            case 'U':
                ++y;
                break;
            case 'D':
                --y;
                break;
            case '_':
                ++dash;
                break;
            }
            ++ptr;
        }
        return abs(x) + abs(y) + dash;
    }
};