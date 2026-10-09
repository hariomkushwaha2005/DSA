#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<pair<int, int>> pre(n, {0, 0});
        pair<int, int> last = {0, 0};
        for (int i = 0; i < n; i++) {
            pre[i] = last;
            if (boxes[i] == '1') {
                pre[i].first += i;
                pre[i].second++;
            }
            last = pre[i];
        }
        int cnt = pre[n - 1].first;
        int balls = pre[n - 1].second;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = pre[i].second * i - pre[i].first +
                     (balls - pre[i].second) * (n - 1 - i) -
                     (n - 1) * (balls - pre[i].second) + (cnt - pre[i].first);
        }
        return ans;
    }
};