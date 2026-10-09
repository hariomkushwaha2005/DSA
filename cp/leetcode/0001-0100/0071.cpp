#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string s) {
        int n = s.size();
        stack<string> st;
        int i = n - 1;
        while (i >= 0) {
            if (s[i] != '/') {
                int x = i;
                while (i >= 0 && s[i] != '/')
                    --i;
                string cur = s.substr(i + 1, x - i);
                if (cur.size() == 1 && cur[0] == '.')
                    continue;
                else if (cur.size() == 2 && cur[0] == '.' && cur[1] == '.') {
                    st.push(cur);
                    continue;
                } else if (!st.empty() && st.top().size() == 2 &&
                           st.top()[0] == '.' && st.top()[1] == '.') {
                    st.pop();
                    continue;
                }
                st.push(cur);
            }
            --i;
        }
        string ans = "";
        while (!st.empty()) {
            string cur = st.top();
            st.pop();
            if (cur.size() == 2 && cur[0] == '.' && cur[1] == '.')
                continue;
            ans += '/' + cur;
        }
        if (ans.empty())
            ans += '/';
        return ans;
    }
};