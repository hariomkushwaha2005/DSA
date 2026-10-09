#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                mp[nums[i]]++;
            }
        }
        for(int i=0;i<n;i++){
            if(mp.count(nums[i])){
                if(mp[nums[i]]==1) return nums[i];
            }
        }
        return -1;
    }
};