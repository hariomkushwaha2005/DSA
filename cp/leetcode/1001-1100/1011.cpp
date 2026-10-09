#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dayss(vector<int>& weights, int days, int x) {
        int n = weights.size();
        int cnt = 1;
        int load = 0;
        for (int i = 0; i < n; i++) {
            load += weights[i];
            if (load > x) {
                cnt++;
                load = weights[i];
            }
            if (cnt > days)
                break;
        }
        return cnt;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxx = weights[0], sum = maxx;
        for (int i = 1; i < n; i++) {
            maxx = max(maxx, weights[i]);
            sum += weights[i];
        }
        int low = maxx, high = sum;
        while (low <= high) {
            int mid = (low + high) / 2;
            int x = dayss(weights, days, mid);
            if (x <= days)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};