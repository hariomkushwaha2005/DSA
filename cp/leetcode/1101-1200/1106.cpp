#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool parse(int &i, string& s) {
        char c = s[i];
        i++;
        if (c == 't')
            return 1;
        if (c == 'f')
            return 0;

        if (c == '!') {
            i++;
            bool res = !parse(i, s);
            i++;
            return res;
        }
        bool ia = c == '&';
        bool ans = ia ? 1 : 0;
        i++;
        while (s[i] != ')') {
            if (s[i] == ',') {
                i++;
                continue;
            }
            if (ia)
                ans &= parse(i, s);
            else
                ans |= parse(i, s);
        }
        i++;
        return ans;
    }

public:
    bool parseBoolExpr(string s) {
        int i = 0;
        return parse(i,s);
    }
};