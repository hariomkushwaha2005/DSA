#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        return (nums[0] + nums[1] <= nums[2])                   ? "none"
               : (nums[0] == nums[2])                           ? "equilateral"
               : ((nums[1] == nums[2]) || (nums[0] == nums[1])) ? "isosceles"
                                                                : "scalene";
    }
};