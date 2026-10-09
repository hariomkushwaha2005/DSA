#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, pair<long long, int>> total;
        for (int i = 0; i < n; i++) {
            total[nums[i]].first += i;
            total[nums[i]].second++;
        }
        vector<long long> arr(n, 0);
        unordered_map<int, pair<long long, int>> prefix;
        for (int i = 0; i < n; i++) {
            prefix[nums[i]].first += i;
            prefix[nums[i]].second++;

            long long left = prefix[nums[i]].first;
            long long lcnt = prefix[nums[i]].second;

            long long right = total[nums[i]].first - prefix[nums[i]].first;
            long long rcnt = total[nums[i]].second - prefix[nums[i]].second;

            arr[i] = (lcnt * i - left) + (right - rcnt * i);
        }
        return arr;
    }
};