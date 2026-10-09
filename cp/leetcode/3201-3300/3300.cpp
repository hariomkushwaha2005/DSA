#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int minn = 1e9;
        for (auto& it : nums) {
            int sum = 0;
            while (it > 0) {
                sum += it % 10;
                it /= 10;
            }
            it = sum;
            minn = min(minn, sum);
        }
        return minn;
    }
};