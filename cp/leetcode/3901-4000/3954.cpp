#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans = 0;
        for(int i = 1; i <= n + k; ++i){
            if(!(i&n) && abs(n - i) <= k) ans+= i; 
        }
        return ans;
    }
};