#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int dist = 0, free = 0;
        for (auto c : moves) {
            if (c == 'L') {
                dist--;
            } else if (c == 'R') {
                dist++;
            } else {
                free++;
            }
        }
        return abs(dist) + free;
    }
};