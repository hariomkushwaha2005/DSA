#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int tar = tickets[k];
        int ans = k + 1;
        tar--;
        if (tar == 0)
            return ans;
        vector<int> v(tar, 0);
        for (int i = 0; i < k; ++i) {
            tickets[i]--;
            if (tickets[i] < tar)
                v[tickets[i]]++;
        }
        for (int i = k + 1; i < n; ++i) {
            if (tickets[i] < tar)
                v[tickets[i]]++;
        }
        int sum = 0;
        while (tar > 0) {
            sum += v[tickets[k] - tar - 1];
            ans += n - sum;
            tar--;
        }
        return ans;
    }
};