#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n = landDuration.size();
        int m = waterDuration.size();
        int minland = INT_MAX;
        for (int i = 0; i < n; i++) {
            minland = min(minland, landStartTime[i] + landDuration[i]);
        }
        int minwater = INT_MAX;
        for (int i = 0; i < m; i++) {
            minwater = min(minwater, waterStartTime[i] + waterDuration[i]);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, max(minwater, landStartTime[i]) + landDuration[i]);
        }
        for (int i = 0; i < m; i++) {
            ans = min(ans, max(minland, waterStartTime[i]) + waterDuration[i]);
        }
        return ans;
    }
};