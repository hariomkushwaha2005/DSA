#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(const vector<int>& hours, int target) {
        int ans = 0;
        for (int x : hours) {
            ans += (x >= target);
        }
        return ans;
    }
};