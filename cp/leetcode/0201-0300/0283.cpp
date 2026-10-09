#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& A) {
        int n = A.size();
        int l = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] != 0) {
                A[l] = A[i];
                l++;
            }
        }
        for (int j = l; j < n; j++) {
            A[j] = 0;
        }
    }
};