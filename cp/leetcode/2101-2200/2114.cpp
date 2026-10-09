#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for (string& s : sentences) {
            int cnt = 0;
            for (char c : s) {
                if (c == ' ')
                    cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans + 1;
    }
};