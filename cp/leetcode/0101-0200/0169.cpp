#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> help(vector<int> &nums, int low, int high)
    {
        if (low == high)
            return {nums[low], 1};
        int mid = low + (high - mid) / 2;
        pair<int, int> p1 = help(nums, low, mid);
        pair<int, int> p2 = help(nums, mid + 1, high);

        if (p1.first == p2.first)
            return {p1.first, p1.second + p2.second};
        if (p1.second >= p2.second)
            return {p1.first, p1.second - p2.second};
        return {p2.first, p2.second - p1.second};
    }
    int majorityElement(vector<int> &nums)
    {
        return help(nums, 0, nums.size() - 1).first;
    }
};