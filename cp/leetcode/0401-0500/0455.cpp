#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n=g.size(),m=s.size();
        int l=0,r=0;
        int ans=0;
        while(l<n&&r<m){
            if(g[l]<=s[r]){
                ans++;
                l++;
                r++;
            }
            else r++;
        }
        return ans;
    }
};