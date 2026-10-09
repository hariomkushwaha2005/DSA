#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0,cnt2=0,el1=INT_MIN,el2=INT_MAX;
        for(int i=0;i<n;i++){
            if(cnt1==0&&nums[i]!=el2){
                cnt1++;
                el1=nums[i];
            }
            else if(cnt2==0&&nums[i]!=el1){
                cnt2++;
                el2=nums[i];
            }
            else if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        int mini=1+n/3;
        vector<int>v;
        for(int i=0;i<n;i++){
            if(nums[i]==el1) cnt1++;
            if(nums[i]==el2)cnt2++;
            if(cnt1==mini) {
                v.push_back(el1);
                cnt1=INT_MIN;
            }
            if(cnt2==mini){ 
                v.push_back(el2);
                cnt2=INT_MIN;
            }
        }
        return v;
    }
};