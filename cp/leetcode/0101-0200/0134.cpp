#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int curgas = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            curgas += gas[i];
            curgas -= cost[i];
            if (curgas < 0) {
                curgas = 0;
                ans = i + 1;
            }
        }
        for(int i = 0; i < ans; ++i){
            curgas += gas[i];
            curgas -= cost[i];
            if(curgas < 0) return -1;
        }
        return ans;
    }
};