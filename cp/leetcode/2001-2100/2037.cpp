#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMovesToSeat( vector<int>& seats,  vector<int>& students) {
        int arr[101] = {0};
        for (int seat : seats) {
            arr[seat]--;
        }
        for (int stu : students) {
            arr[stu]++;
        }
        int diff = 0, ans = 0;
        for (int x : arr) {
            ans += abs(diff);
            diff += x;
        }
        return ans;
    }
};