#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long> mpp(26);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            mpp[s[i] - 'a'] += cost[i];
        }
        long long maxx = 0, costt = 0;
        for (auto it : mpp) {
            costt += it;
            maxx = max(maxx, it);
        }
        return costt - maxx;
    }
};