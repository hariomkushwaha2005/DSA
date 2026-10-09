#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        int l = 0;
        int r = 0;
        for (int i = 0; i < n/2; i++) {
            while (l < n && nums[l] < 0) {
                l++;
            }
            if(l<n){
                arr[2*i] = nums[l];
                l++;
            }
            while (r < n && nums[r] >= 0) {
                r++;
            }
            if(r<n){
                arr[2*i + 1] = nums[r];
                r++;
            }
        }
        return arr;
    }
};