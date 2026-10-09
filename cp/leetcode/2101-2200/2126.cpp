#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        for (auto& it : asteroids) {
            if (mass >= it) {
                mass = min((int)1e5, mass + it);
            } else
                return false;
        }
        return true;
    }
};