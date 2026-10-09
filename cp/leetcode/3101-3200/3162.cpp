#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        int ans = 0;
        for (int num : nums2) {
            num *= k;
            for (int it : nums1) {
                ans += it% num == 0;
            }
        }
        return ans;
    }
};