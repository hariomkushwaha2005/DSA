#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int arr[101] = {0};
        for(auto &x: friends){
            arr[x]++;
        }
        vector<int> ans;
        for(auto &x:order){
            if(arr[x]) ans.push_back(x);
        }
        return ans;
    }
};