#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                for (int j = i; j < n - 1; j++) {
                    swap(nums[j], nums[j + 1]);
                }
                nums.pop_back();
                n--;
                i--;
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};