#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int part(vector<int>& nums, int st, int end, int pi) {
        int pivot = nums[pi];
        swap(nums[end], nums[pi]);
        int ind = st;
        for (int i = st; i <= end; i++) {
            if (nums[i] > pivot) {
                swap(nums[i], nums[ind]);
                ind++;
            }
        }
        swap(nums[ind], nums[end]);
        return ind;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n)
            return -1;
        int st = 0, end = n - 1;
        while (1) {
            int pi = (rand() % (end - st + 1)) + st;
            pi = part(nums, st, end, pi);
            if (pi == k - 1)
                return nums[k - 1];
            else if (pi > k - 1)
                end = pi - 1;
            else
                st = pi + 1;
        }
        return -1;
    }
};