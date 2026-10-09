#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int arr[51] = {0};
        int ans = 0;
        for(auto &it : nums){
            arr[it]++;
            if(arr[it] == 2) ans^= it;
        }
        return ans;
    }
};