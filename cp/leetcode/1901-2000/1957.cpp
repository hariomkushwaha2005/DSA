#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string t = "";
        char last = ' ';
        char sLast = ' ';
        for (auto& c : s) {
            if (last != sLast)
                t += c;
            else if (c != last)
                t += c;
            sLast = last;
            last = c;
        }
        return t;
    }
};