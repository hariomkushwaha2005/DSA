#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int sl = -1, l = -1, r = 0, streak = 0;
        int ans = 0, curr = 0;
        while (r < fruits.size()) {
            if (fruits[r] == l || fruits[r] == sl) {
                curr++;
            } else {
                curr = streak + 1;
            }

            if (fruits[r] == l) {
                streak++;
            } else {
                streak = 1;
                sl = l;
                l = fruits[r];
            }
            ans = max(ans, curr);
            r++;
        }
        return ans;
    }
};