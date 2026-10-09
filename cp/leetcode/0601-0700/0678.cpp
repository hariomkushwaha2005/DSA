#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int minO = 0, maxO = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                minO++;
                maxO++;
            } else if (s[i] == ')') {
                minO--;
                maxO--;
            } else {
                minO--;
                maxO++;
            }
            if (maxO < 0)
                return false;
            minO = max(minO, 0);
        }
        return minO == 0;
    }
};