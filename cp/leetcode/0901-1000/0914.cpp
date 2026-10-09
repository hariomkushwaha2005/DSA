#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int arr[1001] = {0};
        for (auto& x : deck)
            arr[x]++;
        int minn = 1000;
        for (auto& x : arr)
            if (x > 0)
                minn = min(minn, x);
        for(auto& x : arr) {
            if (x > 0)
                minn = __gcd(minn, x);
        }
        return minn > 1;
    }
};