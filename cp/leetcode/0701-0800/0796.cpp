#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size(), m = goal.size(), l = 0;
        if (n != m)
            return false;
        while (l < n) {
            if (s[l] != goal[0])
                l++;
            else {
                int flag = 0;
                for (int i = l; i < n + l; i++) {
                    if (s[i % n] != goal[i - l]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                    return true;
                l++;
            }
        }
        return false;
    }
};