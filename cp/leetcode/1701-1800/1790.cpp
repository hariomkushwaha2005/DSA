#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        if (s2.size() != n)
            return false;
        int i = 0, last1 = -1, last2 = -1;
        int cnt = 0;
        while (i < n) {
            if (s1[i] != s2[i]) {
                cnt++;
                if (last1 == -1)
                    last1 = i;
                else
                    last2 = i;
            }
            if (cnt > 2)
                return false;
            i++;
        }
        if(cnt == 1) return false;
        if(cnt == 2 && (s1[last1] != s2[last2] || s2[last1] != s1[last2])) return false;
        return true;
    }
};