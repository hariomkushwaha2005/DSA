#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> up, low;
        int cnt = 0;
        for (auto& c : word) {
            up.insert(c);
            if (up.count(c - 32) && !low.count(c)) {
                low.insert(c);
            }
        }
        for(auto &c : up){
            if(up.count(c + 32)) cnt++;
        }
        return cnt - (int)low.size();
    }
};