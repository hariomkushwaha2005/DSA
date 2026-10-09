#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), sum = 0;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        int ans = sum;
        for (int i = 0; i < k; i++) {
            sum = sum + cardPoints[n - 1 - i] - cardPoints[k - 1 - i];
            ans = max(sum, ans);
        }
        return ans;
    }
};