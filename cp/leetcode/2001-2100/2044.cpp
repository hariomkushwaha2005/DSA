#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMaxOrSubsets(const vector<int>& nums) {
        int n = nums.size();
        int arr[1 << 17] = {0};
        arr[0] = 1;
        int orr = 0;
        for (int num : nums) {
            for (int i = orr; i >= 0; i--) {
                arr[i | num] += arr[i];
            }
            orr |= num;
        }
        return arr[orr];
    }
};