#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool jb(unordered_map<char, int>& mpp) {
        for (auto it : mpp) {
            if (it.second > 0)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        unordered_map<char, int> mpp;
        for (int i = 0; i < t.size(); i++) {
            mpp[t[i]]++;
        }
        int l = 0, si = -1, len = INT_MAX;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            if (mpp.count(s[i]))
                mpp[s[i]]--;
            while (jb(mpp)) {
                if (len > i - l + 1) {
                    len = i - l + 1;
                    si = l;
                }
                mp[s[l]]--;
                if (mpp.count(s[l]))
                    mpp[s[l]]++;
                l++;
            }
        }
        if (len == INT_MAX)
            return "";
        return s.substr(si, len);
    }
};