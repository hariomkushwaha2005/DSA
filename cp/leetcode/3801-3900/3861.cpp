#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans=-1;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]>=itemSize){
                if(ans==-1){
                    ans=i;
                    continue;
                }
                else{
                    if(capacity[i]<capacity[ans]) ans=i;
                }
            }
        }
        return ans;
    }
};