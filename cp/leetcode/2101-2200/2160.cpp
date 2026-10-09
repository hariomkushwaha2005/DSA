#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        int arr[10] = {0};
        while (num > 0) {
            arr[num % 10]++;
            num /= 10;
        }
        int ten = 2, ans = 0;
        for (int i = 0; i < 10; i++) {
            if (arr[i]) {
                while (arr[i]) {
                    if (ten) {
                        ans += i * 10;
                        ten--;
                    } else {
                        ans += i;
                    }
                    arr[i]--;
                }
            }
        }
        return ans;
    }
};