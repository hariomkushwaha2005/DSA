#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& v) {
        int n = v.size();
        int cnt = 0;
        int flag = 1;
        while (flag) {
            flag = 0;
            int x = INT_MAX;
            int l = -1;
            for (int i = 1; i < n; i++) {
                if (v[i] < v[i - 1]) {
                    flag = 1;
                }
                if (1LL * v[i] + 1LL * v[i - 1] < x) {
                    x = v[i] + v[i - 1];
                    l = i;
                }
            }
            if (flag) {
                v[l - 1] = v[l] + v[l - 1];
                cnt++;
                for (int i = l; i < n - 1; i++) {
                    v[i] = v[i + 1];
                }
                v[n - 1] = INT_MAX;
            }
        }
        return cnt;
    }
};