#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        int bright = (brightness + 2) / 3;
        int intst = 0;
        int intend = -1;
        ll len = 0;
        sort(intervals.begin(), intervals.end());
        for (auto& it : intervals) {
            if (it[0] > intend) {
                len += intend - intst + 1;
                intst = it[0];
                intend = it[1];
            } else {
                intend = max(intend, it[1]);
            }
        }
        len += intend - intst + 1;
        return 1LL * len * bright;
    }
};