#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int arr[10] = {0};
        int bull = 0;
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                bull++;
            } else {
                arr[secret[i] - '0']++;
                arr[guess[i] - '0']--;
            }
        }
        int ac = 0;
        for (int num : arr)
            ac += abs(num);
        int cow = ((n << 1) - (bull << 1) - ac) / 2;
        return to_string(bull) + 'A' + to_string(cow) + 'B';
    }
};