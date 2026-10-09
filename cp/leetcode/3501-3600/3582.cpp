#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string generateTag(string caption) {
        int n = caption.size();
        string ans = "#";
        bool last = 0;
        int i = 0;
        while (caption[i] == ' ')
            i++;
        if (caption[i] <= 'Z')
            caption[i] += 32;
        for (; i < n; i++) {
            if (caption[i] == ' ') {
                last = 1;
                continue;
            }
            if (last && caption[i] >= 'a')
                caption[i] -= 32;
            if (!last && caption[i] <= 'Z')
                caption[i] += 32;
            ans += caption[i];
            if (ans.size() == 100)
                break;
            last = 0;
        }
        return ans;
    }
};