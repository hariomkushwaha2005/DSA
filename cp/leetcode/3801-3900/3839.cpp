

#include <bits/stdc++.h>
using namespace std;class Solution {
public:
    bool check(string& s, string& a, int k) {
        if (s.size() < k || a.size() < k)
            return false;
        for (int i = 0; i < k; i++) {
            if (s[i] != a[i])
                return false;
        }
        return true;
    }
    int prefixConnected(vector<string>& words, int k) {
        int n = words.size();
        sort(words.begin(), words.end());
        int i = 0, cnt = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && check(words[i], words[j], k))
                j++;
            if (j > (i + 1))
                cnt++;
            i = j;
        }
        return cnt;
    }
};