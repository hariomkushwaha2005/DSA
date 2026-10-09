#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        bool arr[58] = {0};
        for (auto& c : jewels)
            arr[c - 'A'] = 1;
        for (auto& c : stones) {
            if (arr[c - 'A'])
                ans++;
        }
        return ans;
    }
};