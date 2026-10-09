#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> idx(n);
        for (int i = 0; i < n; ++i)
            idx[row[i]] = i;
        int swaps = 0;
        for (int i = 0; i < n; i += 2) {
            int want = (row[i] & 1) ? row[i] - 1 : row[i] + 1;
            if (row[i + 1] == want)
                continue;
            int widx = idx[want];
            swap(row[i + 1], row[widx]);
            idx[row[widx]] = widx;
            swaps++;
        }
        return swaps;
    }
};