#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxx = 1;
        int ind = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 1;
            int x = i;
            int l = 1;
            while (s[x] == s[x + 1]) {
                cnt++;
                x++;
                if(x==n-1) break;
            }
            while (i - l >= 0 && x + l < n && s[i - l] == s[x + l]) {
                cnt+=2;
                l++;
            }
            if (cnt > maxx) {
                maxx = cnt;
                ind = i - l + 1;
            }
        }
        string ans = s.substr(ind, maxx);
        return ans;
    }
};