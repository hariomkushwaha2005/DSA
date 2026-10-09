#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string majorityFrequencyGroup(string s) {
        int freq[26] = {0};
        for (auto& c : s)
            freq[c - 'a']++;
        int arr[101] = {0};
        int ind = 1;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0)
                continue;
            arr[freq[i]]++;
            if (arr[freq[i]] > arr[ind] ||
                (arr[freq[i]] == arr[ind] && ind < freq[i]))
                ind = freq[i];
        }
        string x = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] == ind)
                x += 'a' + i;
        }
        return x;
    }
};