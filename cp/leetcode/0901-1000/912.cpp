#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        int arr[100001] = {0};
        for (int i : nums)
            arr[50000 + i]++;
        int j = 0;
        for (int i = 0; i < 100001; ++i)
        {
            while (arr[i] > 0)
            {
                nums[j++] = i - 50000;
                arr[i]--;
            }
        }
        return nums;
    }
};