#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int dist = 1e5, ans = -1;
        int i = 0;
        for(auto &it : points){
            if(it[0] == x && abs(y - it[1]) < dist){
                ans = i;
                dist = abs(y - it[1]);
            }
            if(it[1] == y && abs(x - it[0]) < dist){
                dist = abs(x - it[0]);
                ans = i;
            }
            i++;
        }
        return ans;
    }
};