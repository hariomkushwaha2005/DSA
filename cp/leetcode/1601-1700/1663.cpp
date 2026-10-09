#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n, 'a');
        k -= n;
        int i = n - 1;
        while (k > 0) {
            int minn = min(k, 25);
            s[i] += minn;
            --i;
            k -= minn;
        }
        return s;
    }
};