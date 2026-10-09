#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> ans;
        for (int i = 0; i < n; i += k) {
            string x = s.substr(i, k);
            if (x.length() < k) {

                for (int j = x.length(); j < k; j++) {
                    x += fill;
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};