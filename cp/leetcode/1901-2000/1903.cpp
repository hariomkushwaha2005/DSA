#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string& num) {
        int i = num.size() - 1;
        while (i >= 0 && !(num[i] & 1))
            --i;
        // if(i < 0) return "";
        return num.substr(0, i + 1);
    }
};