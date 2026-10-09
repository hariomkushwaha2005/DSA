#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // private:
    //     bool match(string& a, string& b) {
    //         int n = a.size(), m = b.size();
    //         int i = 0, j = 0;
    //         int cnt = 0;
    //         while (j < m) {
    //             if (i < n && a[i] == b[j]) {
    //                 i++;
    //                 j++;
    //             } else {
    //                 j++;
    //             }
    //         }
    //         return i == n;
    //     }

public:
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); });
        unordered_map<string, int> dp;
        int ans = 0;
        for (const string &word : words)
        {
            int cur = 1;
            for (int i = 0; i < word.size(); i++)
            {
                string pre = word.substr(0, i) + word.substr(i + 1);
                if (dp.count(pre))
                {
                    cur = max(cur, 1 + dp[pre]);
                }
            }
            dp[word] = cur;
            ans = max(ans, cur);
        }
        return ans;
    }
};