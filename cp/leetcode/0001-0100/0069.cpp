#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x / 2;
        if(x==0) return 0;
        int ans = 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};