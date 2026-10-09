#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        if(x < y) sort(s.rbegin(), s.rend());
        else{
            sort(s.begin(), s.end());
        }
        return s;
    }
};