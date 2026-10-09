#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        vector<bool> vis(n,0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                ans++;
                stack<int> st;
                st.push(i);
                while(!st.empty()){
                    int x = st.top();
                    st.pop();
                    if(vis[x]) continue;
                    vis[x] = 1;
                    for(int j = 0; j < n; j++){
                        if(isConnected[x][j]&&!vis[j]) st.push(j);
                    }
                }
            }
        }
        return ans;
    }
};