#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5)
                five++;
            else if (bills[i] == 10) {
                five--;
                ten++;
            } else {
                five--;
                if(ten>0) ten--;
                else five-=2;
            }
            if (five < 0)
                return false;
        }
        return true;
    }
};