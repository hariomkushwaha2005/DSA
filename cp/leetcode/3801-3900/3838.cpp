#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for (int i = 0; i < words.size(); i++) {
            int val = 0;
            for (int j = 0; j < words[i].size(); j++) {
                val += weights[words[i][j] - 'a'];
            }
            val = val % 26;
            val = 25 - val;
            ans += ('a' + val);
        }
        return ans;
    }
};