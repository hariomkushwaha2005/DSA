#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> stableMountains(const vector<int>& height, int threshold) {
        int n = height.size();
        vector<int> ans;
        ans.reserve(n);
        for(int i = 1; i < n; i++){
            if(height[i - 1] > threshold) ans.push_back(i);
        }
        return ans;
    }
};