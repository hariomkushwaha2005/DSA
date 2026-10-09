#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countValidSubarrays(const vector<int> &nums, int x)
    {
        int n = nums.size();
        int ans = 0;
        uint64_t arr[1500];
        for (int i = 0; i < n; i++)
        {
            arr[i] = nums[i];
        }
        uint64_t target = x;
        for (int i = 0; i < n; i++)
        {
            uint64_t sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                if (sum % 10 == target)
                {
                    uint64_t temp = sum;

                    if (temp >= 1000000000000ULL)
                        temp /= 1000000000000ULL;
                    else if (temp >= 100000000000ULL)
                        temp /= 100000000000ULL;
                    else if (temp >= 10000000000ULL)
                        temp /= 10000000000ULL;
                    else if (temp >= 1000000000ULL)
                        temp /= 1000000000ULL;
                    else if (temp >= 100000000ULL)
                        temp /= 100000000ULL;
                    else if (temp >= 10000000ULL)
                        temp /= 10000000ULL;
                    else if (temp >= 1000000ULL)
                        temp /= 1000000ULL;
                    else if (temp >= 100000ULL)
                        temp /= 100000ULL;
                    else if (temp >= 10000ULL)
                        temp /= 10000ULL;
                    else if (temp >= 1000ULL)
                        temp /= 1000ULL;
                    else if (temp >= 100ULL)
                        temp /= 100ULL;
                    else if (temp >= 10ULL)
                        temp /= 10ULL;

                    ans += temp == target;
                }
            }
        }
        return ans;
    }
};