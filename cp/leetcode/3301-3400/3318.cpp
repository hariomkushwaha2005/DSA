#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        int arr[51] = {0};
        for (int i = 0; i < k - 1; i++) {
            arr[nums[i]]++;
        }
        for (int i = 0; i < n - k + 1; i++) {
            arr[nums[i + k - 1]]++;
            pair<int, int> vec[51] = {{0, 0}};
            for (int j = 0; j < 51; j++) {
                vec[j] = {arr[j], j};
            }
            int sum = 0;
            sort(vec, vec + 51, greater<pair<int, int>>());
            for (int j = 0; j < x; j++) {
                sum += (vec[j].first * vec[j].second);
            }
            ans.push_back(sum);
            arr[nums[i]]--;
        }
        return ans;
    }
};