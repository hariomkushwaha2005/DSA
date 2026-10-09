#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        for(auto it : mp){
            if(ans.size()==0) ans.push_back(it.first);
            else if(mp[ans.back()]!=it.second){
                ans.push_back(it.first);
                break;
            }
        }
        if(ans.size()<2) return {-1,-1};
        return ans;
    }
};