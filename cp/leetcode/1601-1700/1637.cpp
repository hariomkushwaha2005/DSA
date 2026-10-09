#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        int minn = INT_MAX, maxx = -1;
        for (const auto& it : points) {
            minn = min(minn, it[0]);
            maxx = max(maxx, it[0]);
        }
        int size = max(1, (maxx - minn) / (n - 1));
        int count = 1 + (maxx - minn) / size;
        vector<int> minx(count, INT_MAX);
        vector<int> maxxx(count, -1);
        for (int i = 0; i < n; i++) {
            int x = points[i][0];
            int idx = (x - minn) / size;
            minx[idx] = min(minx[idx], x);
            maxxx[idx] = max(maxxx[idx], x);
        }
        int last = maxxx[0];
        int ans = 0;
        for (int i = 1; i < count; i++) {
            if (minx[i] == INT_MAX)
                continue;
            ans = max(ans, minx[i] - last);
            last = maxxx[i];
        }
        return ans;
    }
};