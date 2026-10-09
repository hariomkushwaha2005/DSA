#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        int n = nums.size();
        int freq[100001] = {0};
        int l = 0, r = 0, f = 0;
        int lessm = 0, distinct = 0;
        long long cnt = 0;

        while (r < n) {
            freq[nums[r]]++;
            if (freq[nums[r]] == 1) {
                distinct++;
                lessm++;
            }
            if (freq[nums[r]] == m)
                lessm--;
            r++;

            while (distinct > k) {
                freq[nums[f]]--;
                if (freq[nums[f]] == 0) {
                    distinct--;
                    lessm--;
                }
                if (freq[nums[f]] == m - 1)
                    lessm++;
                f++;
                l = f;
            }

            if (lessm == 0 && distinct == k) {
                while (freq[nums[f]] > m)
                    freq[nums[f++]]--;
                cnt += f - l + 1;
            }
        }
        return cnt;
    }
};