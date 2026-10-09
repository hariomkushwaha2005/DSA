#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPalindrom(string& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i])
                return false;
        }
        return true;
    }

public:
    string firstPalindrome(vector<string>& words) {
        for(auto s: words){
            if(isPalindrom(s)) return s;
        }
        return "";
    }
};
