#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPermutationDifference(const string& s, const string& t) {
        int arr[26] = {0};
        int i = 0;
        for (char c : s) {
            arr[c - 'a'] += i;
            i++;
        }
        i = 0;
        int ans = 0;
        for (char c : t) {
            ans += abs(arr[c - 'a'] - i);
            i++;
        }
        return ans;
    }
};