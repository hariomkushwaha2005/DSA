#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string concatHex36(int n) {
        int x = n * n * n;
        string s = "";
        while (x > 0) {
            int ld = x % 36;
            x = x / 36;
            if (ld > 9) {
                s += 'A' + ld - 10;
            }
            else{
                s += '0' + ld;
            }
        }
        x = n * n;
        while(x > 0){
            int ld = x % 16;
            x = x / 16;
            if (ld > 9) {
                s += 'A' + ld - 10;
            }
            else{
                s += '0' + ld;
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
};