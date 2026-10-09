#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getend(int st, string& s, vector<int>& left, vector<int>& right) {
        int end = right[s[st] - 'a'];
        for (int i = st; i < end; i++) {
            if (left[s[i] - 'a'] < st)
                return -1;
            end = max(end, right[s[i] - 'a']);
        }
        return end;
    }

public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> left(26, -1), right(26, -1);
        for (int i = 0; i < n; i++) {
            if (left[s[i] - 'a'] == -1)
                left[s[i] - 'a'] = i;
            right[s[i] - 'a'] = i;
        }
        vector<string> ans;
        int lastend = -1;
        for (int i = 0; i < n; i++) {
            if (i == left[s[i] - 'a']) {
                int end = getend(i, s, left, right);
                if (end != -1) {
                    if (i > lastend)
                        ans.push_back("");
                    ans.back() = s.substr(i, end - i + 1);
                    lastend = end;
                }
            }
        }
        return ans;
    }
};