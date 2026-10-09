#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(const vector<int>& heights) {
        int n = heights.size();
        int i = 0, j = n - 1;
        int ans = 0;
        while (i < j) {
            int len = j - i;
            int minn;
            if (heights[i] < heights[j]) {
                minn = heights[i];
                while (i < j && heights[i] <= minn)
                    ++i;
            } else {
                minn = heights[j];
                while (i < j && heights[j] <= minn)
                    --j;
            }
            int cur = len * minn;
            if (ans < cur)
                ans = cur;
        }
        return ans;
    }
};