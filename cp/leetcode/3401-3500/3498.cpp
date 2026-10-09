#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseDegree(const string& s) {
        int ans = 0;
        int i = 1;
        for (char c : s) {
            ans += ('z' - c + 1) * i;
            i++;
        }
        return ans;
    }
};