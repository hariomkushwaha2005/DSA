#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string interpret(string command) {
        int n = command.size();
        string s = "";
        for (int i = 0; i < n; i++) {
            if (command[i] == 'G')
                s += 'G';
            else if (command[i] == ')') {
                if (command[i - 1] == '(')
                    s += 'o';
                else
                    s += "al";
            }
        }
        return s;
    }
};