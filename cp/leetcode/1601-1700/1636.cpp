#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int arr[201] = {0};
        for (int num : nums)
            arr[num + 100]++;
        sort(nums.begin(), nums.end(), [&](const int a, const int b) {
            return arr[a + 100] == arr[b + 100] ? a > b
                                                : arr[a + 100] < arr[b + 100];
        });
        return nums;
    }
};