#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        int n = word.size();
        int freq[26] = {0};
        for (auto& c : word)
            freq[c - 'a']++;
        for (int i = 0; i < n; i++) {
            freq[word[i] - 'a']--;
            int last = (freq[word[i] - 'a'] != 0) ? freq[word[i] - 'a']
                       : (i != 0)                 ? freq[word[0] - 'a']
                                                  : freq[word[1] - 'a'];
            bool match = true;
            for (auto& c : word) {
                if (freq[c - 'a'] == last || freq[c - 'a'] == 0)
                    continue;
                else {
                    match = false;
                    break;
                }
            }
            if (match)
                return true;
            freq[word[i] - 'a']++;
        }
        return false;
    }
};