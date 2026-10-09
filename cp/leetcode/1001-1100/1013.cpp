#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for (auto& x : arr)
            sum += x;
        if(sum % 3 != 0) return 0;
        int cnt = 0;
        int cur =0;
        for(auto &x: arr){
            cur += x;
            if(cur == sum/3){
                cur = 0;
                cnt++;
            }
        }
        return cnt >= 3;
    }
};