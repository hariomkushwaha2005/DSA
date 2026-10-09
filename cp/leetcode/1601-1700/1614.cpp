#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int maxx = 0, cnt = 0;
        for (auto it : s) {
            if (it == '(')
                cnt++;
            else if (it == ')')
                cnt--;
            maxx = max(maxx, cnt);
        }
        return maxx;
    }
};