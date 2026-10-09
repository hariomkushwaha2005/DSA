#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cb(vector<int>& bloomDay, int m, int k, int x) {
        int n = bloomDay.size();
        int cnt = 0;
        int b = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= x)
                cnt++;
            else {
                b += cnt / k;
                cnt = 0;
            }
            if (b > m)
                return b;
        }
        b += cnt / k;
        return b;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < (long long)m * k)
            return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while (low <= high) {
            int mid = (low + high) / 2;
            int f = cb(bloomDay, m, k, mid);
            if (f < m)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};