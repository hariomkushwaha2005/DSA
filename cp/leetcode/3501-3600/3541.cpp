#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreqSum(const string& s) {
        int arr[26] = {0};
        for (char c : s) {
            arr[c - 'a']++;
        }
        int maxVowel = 0, maxConsonant = 0;
        for (int i = 0; i < 26; i++) {
            if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20)
                maxVowel = max(maxVowel, arr[i]);
            else
                maxConsonant = max(maxConsonant, arr[i]);
        }
        return maxVowel + maxConsonant;
    }
};