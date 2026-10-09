#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string& s) {
        int n = s.size();
        stack<pair<int, string>> st;
        string ans = "";
        int i = 0;
        while (i < n) {
            if (s[i] <= '9' && s[i] >= '0') {
                int rep = 0;
                while (s[i] <= '9' && s[i] >= '0') {
                    rep = rep * 10 + s[i] - '0';
                    i++;
                }
                st.push({rep, ""});
            } else if (s[i] <= 'z' && s[i] >= 'a') {
                int idx = i;
                while (s[i] <= 'z' && s[i] >= 'a') {
                    i++;
                }
                string cur = s.substr(idx, i - idx);
                if (st.empty())
                    ans += cur;
                else
                    st.top().second += cur;
            } else if (s[i] == ']') {
                int rep = st.top().first;
                string cur = st.top().second;
                st.pop();
                if (st.empty()) {
                    while (rep--)
                        ans += cur;
                } else {
                    while (rep--)
                        st.top().second += cur;
                }
                i++;
            } else
                i++;
        }
        return ans;
    }
};