#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string mikasa(string& s, int n) {
        int cnt = 0;
        char ch = s[0];
        string ans;
        for (auto& c : s) {
            if (c == ch) {
                cnt++;
            } else {
                ans += to_string(cnt);
                ans += ch;
                cnt = 1;
                ch = c;
            }
        }
        ans += to_string(cnt);
        ans += ch;
        if (n == 1)
            return ans;
        return mikasa(ans, n - 1);
    }

public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; i++) {
            string ans;
            int cnt = 0;
            char ch = s[0];
            for (auto& c : s) {
                if (c == ch) {
                    cnt++;
                } else {
                    ans += to_string(cnt);
                    ans += ch;
                    cnt = 1;
                    ch = c;
                }
            }
            ans += to_string(cnt);
            ans += ch;
            swap(s,ans);
        }
        return s;
    }
};