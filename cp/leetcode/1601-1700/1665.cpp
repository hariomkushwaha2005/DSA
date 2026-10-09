#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& task) {
        int n = task.size();
        sort(task.begin(), task.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] - a[0] > b[1] - b[0];
             });
        int cur = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (cur < task[i][1]) {
                ans += (task[i][1] - cur);
                cur = task[i][1];
            }
            cur -= task[i][0];
        }
        return ans;
    }
};