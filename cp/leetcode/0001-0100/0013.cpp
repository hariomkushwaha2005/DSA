#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'V')
                sum += 5;
            else if (s[i] == 'L')
                sum += 50;
            else if (s[i] == 'D')
                sum += 500;
            else if (s[i] == 'M')
                sum += 1000;
            else {
                if (s[i] == 'I') {
                    if (i == n - 1)
                        sum++;
                    else {
                        if (s[i + 1] == 'V' || s[i + 1] == 'X')
                            sum--;
                        else
                            sum++;
                    }
                } else if (s[i] == 'X') {
                    if (i == n - 1)
                        sum += 10;
                    else {
                        if (s[i + 1] == 'L' || s[i + 1] == 'C')
                            sum -= 10;
                        else
                            sum += 10;
                    }
                } else {
                    if (i == n - 1)
                        sum += 100;
                    else {
                        if (s[i + 1] == 'D' || s[i + 1] == 'M')
                            sum -= 100;
                        else
                            sum += 100;
                    }
                }
            }
        }
        return sum;
    }
};