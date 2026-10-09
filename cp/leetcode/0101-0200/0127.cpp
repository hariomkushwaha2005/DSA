#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int cnt = 1;
        if (!st.count(endWord))
            return 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string s = q.front();
                q.pop();
                if (s == endWord)
                    return cnt;
                for (int j = 0; j < s.size(); j++) {
                    char eren = s[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == eren)
                            continue;
                        s[j] = c;
                        if (st.count(s)){
                            q.push(s);
                            st.erase(s);
                        }
                    }
                    s[j] = eren;
                }
            }
            cnt++;
        }
        return 0;
    }
};