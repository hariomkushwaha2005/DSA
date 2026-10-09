#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, string> mp;
    int a = 0;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string s = to_string(a++);
        mp[s] = longUrl;
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) { return mp[shortUrl]; }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));