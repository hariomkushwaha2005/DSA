#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();
        bool flag = 1;
        int cnt = 0;
        int chor = 1;
        if (n == 1)
            return {0, 0};
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) {
                if (!flag)
                    cnt++;
            } else {
                if (flag)
                    cnt++;
            }
            flag = !flag;
            if (i > 0 && nums[i] == nums[i - 1])
                chor++;
        }
        flag = 1;
        if (cnt > n - cnt) {
            cnt = n - cnt;
            flag = 0;
        }
        int minn = INT_MAX, maxx = INT_MIN;
        bool hari = flag;
        for (int i = 0; i < n; i++) {
            if (nums[i] & 1) {
                if (!flag) {
                    maxx = max(maxx, nums[i] - 1);
                    minn = min(minn, nums[i] + 1);
                } else {
                    maxx = max(maxx, nums[i]);
                    minn = min(minn, nums[i]);
                }
            } else {
                if (flag) {
                    maxx = max(maxx, nums[i] - 1);
                    minn = min(minn, nums[i] + 1);
                } else {
                    maxx = max(maxx, nums[i]);
                    minn = min(minn, nums[i]);
                }
            }
            flag = !flag;
        }
        if (cnt == n - cnt) {
            flag = !hari;
            int mini = INT_MAX, maxi = INT_MIN;
            for (int i = 0; i < n; i++) {
                if (nums[i] & 1) {
                    if (!flag) {
                        maxi = max(maxi, nums[i] - 1);
                        mini = min(mini, nums[i] + 1);
                    } else {
                        maxi = max(maxi, nums[i]);
                        mini = min(mini, nums[i]);
                    }
                } else {
                    if (flag) {
                        maxi = max(maxi, nums[i] - 1);
                        mini = min(mini, nums[i] + 1);
                    } else {
                        maxi = max(maxi, nums[i]);
                        mini = min(mini, nums[i]);
                    }
                }
                flag = !flag;
            }
            if (maxx - minn > maxi - mini) {
                maxx = maxi;
                minn = mini;
            }
        }
        if (chor == n)
            return {cnt, 1};
        vector<int> ans;
        ans.push_back(cnt);
        ans.push_back(maxx - minn);
        return ans;
    }
};