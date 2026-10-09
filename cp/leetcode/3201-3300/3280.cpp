#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper function to convert an integer to a binary string
    string toBinary(int n) {
        if (n == 0) return "0";
        string res = "";
        while (n > 0) {
            res.push_back((n % 2 == 0) ? '0' : '1');
            n /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }

public:
    string convertDateToBinary(const string& s) {
        int year = (s[0] - '0') * 1000 + (s[1] - '0') * 100 +
                   (s[2] - '0') * 10 + (s[3] - '0');
        int month = (s[5] - '0') * 10 + (s[6] - '0');
        int day = (s[8] - '0') * 10 + (s[9] - '0');
        
        // Concatenate the binary strings with hyphens
        return toBinary(year) + "-" + toBinary(month) + "-" + toBinary(day);
    }
};