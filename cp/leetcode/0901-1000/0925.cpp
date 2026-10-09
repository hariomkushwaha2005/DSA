#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size();
        if (name[0] != typed[0])
            return false;
        int l = 0;
        for (int i = 0; i < n; i++) {
            while (l < typed.size() && typed[l] != name[i] &&
                   typed[l] == typed[l - 1])
                l++;
            if (l < typed.size() && name[i] == typed[l]) {
                l++;
            } else
                return false;
        }
        while (l < typed.size() && typed[l] == typed[l - 1])
            l++;
        return l == typed.size();
    }
};