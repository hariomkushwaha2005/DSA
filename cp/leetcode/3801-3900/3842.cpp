#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> ans;
        int bulb[101] = {0};
        for (auto& it : bulbs)
            bulb[it] = !bulb[it];
        for(int i = 0; i <= 100; i++){
            if(bulb[i]) ans.push_back(i);
        }
        return ans;
    }
};