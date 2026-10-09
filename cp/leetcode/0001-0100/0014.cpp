#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = INT_MAX;
        for (int i = 0; i < strs.size(); i++) {
            int c = strs[i].size();
            n = min(n, c);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int flag = 0;
            char x = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != x)
                    flag = 1;
            }
            if (flag == 1)
                break;
            cnt++;
        }
        string ans;
        ans = strs[0].substr(0, cnt);
        return ans;
    }
};