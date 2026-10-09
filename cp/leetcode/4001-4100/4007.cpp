#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        int n = planks.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[planks[i]]++;
        }
        vector<int> v;
        for (auto it : mp) {
            v.push_back(it.first);
        }
        unordered_map<int, int> freq;
        for (int i = 0; i < v.size(); ++i) {
            freq[v[i]] += mp[v[i]];
            freq[2 * v[i]] += (mp[v[i]] / 2);
            for (int j = i + 1; j < v.size(); ++j) {
                freq[v[i] + v[j]] += min(mp[v[i]], mp[v[j]]);
            }
        }
        int ans = 0;
        for (auto it : freq) {
            if (ans < it.second) {
                ans = it.second;
            }
        }
        return ans;
    }
};