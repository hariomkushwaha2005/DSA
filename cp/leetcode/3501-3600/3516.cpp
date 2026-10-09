#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xTime = abs(x - z);
        int yTime = abs(y - z);
        return xTime < yTime ? 1 : xTime > yTime ? 2 : 0;
    }
};