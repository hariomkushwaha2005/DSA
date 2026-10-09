#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int range(int n) {
        int low = 9, high = 0;
        while (n > 0) {
            int ld = n % 10;

            if (ld < low)
                low = ld;
            if (ld > high)
                high = ld;

            if (low == 0 && high == 9)
                return 9;

            n /= 10;
        }
        return high - low;
    }

public:
    int maxDigitRange(vector<int>& nums) {
        int ran = 0;
        int ans = 0;
        for (int num : nums) {
            int cur = range(num);
            if (cur > ran) {
                ran = cur;
                ans = num;
            } else if (cur == ran)
                ans += num;
        }
        return ans;
    }
};