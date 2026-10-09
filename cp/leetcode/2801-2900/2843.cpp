#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++) {
            string num = to_string(i);
            int n = num.length();
            if (n & 1)
                continue;
            else {
                int x1 = 0;
                for (int i = 0; i < n / 2; i++) {
                    x1 += num[i];
                }
                int x2 = 0;
                for (int i = n - 1; i >= n / 2; i--) {
                    x2 += num[i];
                }
                if (x1 == x2)
                    ans++;
            }
        }
        return ans;
    }
};