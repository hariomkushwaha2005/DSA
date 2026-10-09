#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n + 1, 0);
        vector<int> v(n);

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if(++freq[A[i]] == 2) ++cnt;
            if(++freq[B[i]] == 2) ++cnt;

            v[i] = cnt;
        }
        return v;
    }
};