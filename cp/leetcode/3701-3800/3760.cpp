#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinct(string s) {
        int arr[26] = {0};
        int cnt = 0;
        for(auto &x : s){
            if(arr[x-'a'] == 0) cnt++;
            arr[x-'a']++;
        }
        return cnt;
    }
};