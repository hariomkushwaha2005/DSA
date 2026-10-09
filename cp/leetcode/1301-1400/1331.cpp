#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        priority_queue<int> pq;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            if(!mp.count(arr[i])) pq.push(arr[i]);
            mp[arr[i]]++;
        }
        while(!pq.empty()){
            mp[pq.top()] = pq.size();
            pq.pop();
        }
        for(int i = 0; i < n; i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};