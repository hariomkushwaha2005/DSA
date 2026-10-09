#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wax(vector<int> piles, int h, int mid) {
        int n = piles.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (piles[i] + mid - 1) / mid;
            if (cnt > h)
                break;
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end(), greater<int>());
        int low = 1, high = piles[0];
        while (low <= high) {
            int mid = (low + high) / 2;
            int cnt = wax(piles, h, mid);
            if (cnt <= h) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};