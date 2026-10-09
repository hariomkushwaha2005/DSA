#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k >= n)
            return "0";
        stack<char> st;
        int r = 0;
        while (r < n) {
            while (!st.empty() && st.top() > num[r] && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[r]);
            r++;
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        ans.erase(0, ans.find_first_not_of('0'));
        if (ans.length() == 0)
            return "0";
        return ans;
    }
};