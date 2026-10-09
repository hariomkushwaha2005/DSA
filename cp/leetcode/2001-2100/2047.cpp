#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool mikasa(string& s, int l, int r) {
        int hy = 0, pun = 0;
        for (int i = l; i <= r; i++) {
            if (s[i] >= '0' && s[i] <= '9')
                return 0;
            else if (s[i] == '-') {
                hy++;
                if ((s[i - 1] <= 'z' && s[i - 1] >= 'a') &&
                    (s[i + 1] <= 'z' && s[i + 1] >= 'a'))
                    continue;
                else
                    return 0;
            } else if (s[i] == '!' || s[i] == '.' || s[i] == ',') {
                pun++;
                if (s[i + 1] == ' ')
                    continue;
                else
                    return false;
            }
        }
        return (hy <= 1 && pun <= 1);
    }

public:
    int countValidWords(string sentence) {
        string final = sentence[0] == ' ' ? "" : " ";
        final += sentence;
        if (sentence[sentence.length() - 1] != ' ')
            final += ' ';
        int last = 0, ans = 0;
        for (int i = 1; i < final.size(); i++) {
            if (final[i] == ' ') {
                if(last != i - 1) ans += mikasa(final, last + 1, i - 1);
                last = i;
            }
        }
        return ans;
    }
};