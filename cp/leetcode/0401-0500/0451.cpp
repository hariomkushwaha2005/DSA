#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<pair<int, char>> v(256);
        for (int i = 0; i < 256; i++) {
            v[i] = {0, i};
        }
        for (int i = 0; i < n; i++) {
            v[s[i]].first++;
        }
        sort(v.begin(), v.end(), greater<>());
        s = "";
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < v[i].first; j++) {
                s += v[i].second;
            }
        }
        return s;
    }
};