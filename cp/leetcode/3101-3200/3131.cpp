#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int min1 = 1000, min2 = 1000;
        for (int i = 0; i < n; i++) {
            min1 = min(min1, nums1[i]);
            min2 = min(min2, nums2[i]);
        }
        return min2 - min1;
    }
};