#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        int r = 0;
        while (r < n) {
            if (asteroids[r] < 0) {
                while (!st.empty() && st.top() > 0 &&
                       st.top() < abs(asteroids[r]))
                    st.pop();
                if (st.empty() || st.top() < 0)
                    st.push(asteroids[r]);
                else if (st.top() > 0 && abs(st.top()) == abs(asteroids[r]))
                    st.pop();
            } else {
                st.push(asteroids[r]);
            }
            r++;
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};