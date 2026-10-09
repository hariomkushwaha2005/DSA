#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> st;
        for (auto& it : candyType)
            st.insert(it);
        return min((int)st.size(), n >> 1);
    }
};