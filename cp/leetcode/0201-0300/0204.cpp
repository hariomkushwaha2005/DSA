#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<int> arr(n, 0);
        int cnt = 0;
        for (int i = 2; i < n; ++i) {
            if (arr[i] == 0) {
                cnt++;
                for (int j = i; j < n; j += i)
                    arr[j] = 1;
            }
        }
        return cnt;
    }
};