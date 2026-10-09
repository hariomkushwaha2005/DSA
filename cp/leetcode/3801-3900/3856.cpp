#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isvowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    string trimTrailingVowels(string s) {
        int cnt = 0, ind = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isvowel(s[i])) {
                cnt++;
            } else {
                cnt = 0;
                ind = i + 1;
            }
        }
        if (ind < s.size())
            s.erase(ind, cnt);
        return s;
    }
};