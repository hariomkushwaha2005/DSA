#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if (n == 1)
            return 0;

        if (n == 2 && s[0] > s[1])
            return -1;

        int minn = 'z', mincnt = 0;
        int maxx = 'a', maxcnt = 0;
        bool flag = true;
        char last = 'a';

        for (auto c : s) {
            if (c < minn) {
                minn = c;
                mincnt = 1;
            } else if (c == minn)
                mincnt++;

            if (maxx < c) {
                maxx = c;
                maxcnt = 1;
            } else if (maxx == c)
                maxcnt++;
            if (last > c)
                flag = false;
            last = c;
        }

        if (flag)
            return 0;

        if (s[0] == maxx && s[n - 1] == minn && mincnt <= 1 && maxcnt <= 1)
            return 3;
        else if (s[0] == minn || s[n - 1] == maxx)
            return 1;

        return 2;
    }
};