#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(string& curr, string& begin, vector<string>& path,
             vector<vector<string>>& ans, unordered_map<string, int>& mp) {

        if (curr == begin) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }
        int n = curr.size();
        int step = mp[curr];
        for (int i = 0; i < n; i++) {
            char c = curr[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch == c)
                    continue;
                curr[i] = ch;
                if (mp.count(curr) && mp[curr] == step - 1) {
                    path.push_back(curr);
                    dfs(curr, begin, path, ans, mp);
                    path.pop_back();
                }
            }
            curr[i] = c;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        unordered_map<string, int> mp;
        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 0;
        st.erase(beginWord);
        bool found = false;
        while (!q.empty() && !found) {
            int size = q.size();
            while (size--) {
                string s = q.front();
                int step = mp[s];
                q.pop();
                int n = s.size();
                for (int i = 0; i < n; i++) {
                    char c = s[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == c)
                            continue;
                        s[i] = ch;
                        if (st.count(s)) {
                            if (s == endWord)
                                found = true;
                            q.push(s);
                            mp[s] = step + 1;
                            st.erase(s);
                        }
                    }
                    s[i] = c;
                }
            }
        }
        vector<vector<string>> ans;
        if (found) {
            vector<string> path = {endWord};
            dfs(endWord, beginWord, path, ans, mp);
        }
        return ans;
    }
};