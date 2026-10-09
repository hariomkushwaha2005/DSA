#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int last = first;
        for (int& val : encoded) {
            val ^= last;
            swap(val, last);
        }
        encoded.push_back(last);
        return encoded;
    }
};