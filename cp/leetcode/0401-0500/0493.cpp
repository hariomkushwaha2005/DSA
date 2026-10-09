#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long merge(vector<int>& arr, long long low, long long mid, long long high) {
        long long cnt = 0;
        long long left = low;
        long long right = mid + 1;
        long long l = low, r = mid + 1;
        while (l <= mid && r <= high) {
            if (arr[l] > (long long)2 * arr[r]) {
                cnt += mid - l + 1;
                r++;
            } else {
                l++;
            }
        }
        vector<long long> temp;
        while (left <= mid && right <= high) {
            if (arr[left] > arr[right]) {
                temp.push_back(arr[right]);
                right++;
            } else {
                temp.push_back(arr[left]);
                left++;
            }
        }
        while (left <= mid) {
            temp.push_back(arr[left++]);
        }
        while (right <= high) {
            temp.push_back(arr[right++]);
        }
        for (long long i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        return cnt;
    }
    long long mergesort(vector<int>& arr, long long low, long long high) {
        if (low == high)
            return 0;
        long long cnt = 0;
        long long mid = (low + high) / 2;
        cnt += mergesort(arr, low, mid);
        cnt += mergesort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size() - 1);
    }
};