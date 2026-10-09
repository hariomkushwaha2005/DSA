#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        int block = (1 << (n - 1));
        if (3 * block < k)
            return "";
        string ans;
        ans.reserve(n);
        int x;
        if (k > (block << 1)) {
            x = (block << 1);
            ans += 'c';
        } else if (k > block) {
            x = block;
            ans += 'b';
        } else {
            x = 0;
            ans += 'a';
        }
        int i = n - 2;
        while (i >= 0) {
            int bit = 1 << i;
            if (k <= (x | bit)) {
                ans += ans.back() == 'a' ? 'b' : 'a';
            } else {
                ans += ans.back() == 'c' ? 'b' : 'c';
                x |= bit;
            }
            i--;
        }
        return ans;
    }
};