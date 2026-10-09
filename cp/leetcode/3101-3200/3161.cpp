#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void update(int x, int val, vector<int>& segment) {
        segment[x] = val;
        x = x / 2;
        while (x > 0) {
            segment[x] = max(segment[2 * x], segment[2 * x + 1]);
            x = x / 2;
        }
    }
    int maxblock(int l, int r, vector<int>& segment) {
        int maxx = segment[r];
        while (l < r) {
            if (l & 1) {
                maxx = max(maxx, segment[l]);
                l++;
            }
            if ((r & 1) == 0) {
                maxx = max(maxx, segment[r]);
                r--;
            }
            l = l / 2;
            r = r / 2;
        }
        maxx = max(maxx, segment[l]);
        return maxx;
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int N = (1 << 16);
        vector<int> segment(2 * N, 0);
        vector<bool> ans;
        set<int> st;
        st.insert(0);
        for (auto& it : queries) {
            if (it[0] == 1) {
                auto next_it = st.upper_bound(it[1]);
                int prev = *std::prev(next_it);
                if (next_it != st.end()) {
                    int next = *next_it;
                    update(N + next, next - it[1], segment);
                }
                update(N + it[1], it[1] - prev, segment);
                st.insert(it[1]);
            } else {
                int block = maxblock(N, N + it[1], segment);
                auto prev_it = prev(st.upper_bound(it[1]));
                int last = *prev_it;
                block = max(block, it[1] - last);
                if (block >= it[2])
                    ans.push_back(1);
                else
                    ans.push_back(0);
            }
        }
        return ans;
    }
};