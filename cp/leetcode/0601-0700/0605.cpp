#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int last = -2;
        for (int i = 0; i < size; i++) {
            if (flowerbed[i] == 1) {
                int len = i - last - 1;
                n -= (len - 1) / 2;
                last = i;
            }
        }
        int len = size - last;
        n -= (len - 1) / 2;
        if(n <= 0) return true;
        return false;
    }
};