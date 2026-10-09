#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string s) {
        int n = s.size();
        unordered_set<char> st;
        for(int i = 0; i < n; i++){
            st.insert(s[i]);
        }
        int cnt = 0;
        for(auto &it : st){
            if(st.count(it + 32)) cnt++;
        }
        return cnt;
    }
};