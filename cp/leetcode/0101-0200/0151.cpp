#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverse(string& s, int start, int end) {
        while (start < end) {
            swap(s[start++], s[end--]);
        }
    }
    string reverseWords(string s) {
        int n = s.size();
        int i = 0, j = 0, start = 0, end = 0;
        reverse(s, 0, n - 1);
        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;
            if (i == n)
                break;
            start = j;
            while (i < n && s[i] != ' ') {
                s[j++] = s[i++];
            }
            end = j - 1;
            reverse(s, start, end);
            if (i < n) {
                s[j++] = ' ';
            }
        }
        if (j > 0 && s[j - 1] == ' ')
            j--;
        return s.substr(0, j);
    }
};