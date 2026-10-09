#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int num = x;
        long long revnum = 0;
        while (num > 0) {
            revnum = revnum * 10 + num % 10;
            num /= 10;
        }
        return revnum == x;
    }
};