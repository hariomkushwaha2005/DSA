#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(const vector<string>& bank) {
        int last = 0, ans = 0;
        for (const string& s : bank) {
            int cur = count(s.begin(), s.end(), '1');
            if (cur > 0) {
                ans += cur * last;
                last = cur;
            }
        }
        return ans;
    }
};