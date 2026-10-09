#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reversearr(vector<int>& arr, int start, int end) {
        while (start <= end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int d = n - k - 1;
        reversearr(nums, 0, d);
        reversearr(nums, d + 1, n - 1);
        reversearr(nums, 0, n - 1);
    }
};