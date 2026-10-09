#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        vector<int> v;
        v.reserve(n);
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                v.push_back(c);
            else {
                if (v.empty() || abs(c - v.back()) > 2)
                    return false;
                v.pop_back();
            }
        }
        return v.size() == 0;
    }
};