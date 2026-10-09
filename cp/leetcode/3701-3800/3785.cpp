#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &nums, vector<int> &forbidden)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == forbidden[i])
                mp[nums[i]].push_back(i);
        }

        priority_queue<pair<int, int>> pq;
        for (auto &it : mp)
        {
            int val = it.first;
            vector<int> indices = it.second;
            pq.push({indices.size(), val});
        }
        int swaps = 0;
        while (pq.size() >= 2)
        {
            int size1 = pq.top().first;
            int val1 = pq.top().second;
            pq.pop();
            int size2 = pq.top().first;
            int val2 = pq.top().second;
            pq.pop();

            swap(nums[mp[val1].back()], nums[mp[val2].back()]);
            mp[val1].pop_back();
            size1--;
            mp[val2].pop_back();
            size2--;
            swaps++;
            if (size1 > 0)
                pq.push({size1, val1});
            if (size2 > 0)
                pq.push({size2, val2});
        }
        if (!pq.empty())
        {
            int val = pq.top().second;
            pq.pop();
            int i = 0;
            while (!mp[val].empty())
            {
                for (; i < n; i++)
                {
                    if (nums[i] != forbidden[mp[val].back()] &&
                        nums[mp[val].back()] != forbidden[i])
                    {
                        swap(nums[i], nums[mp[val].back()]);
                        swaps++;
                        i++;
                        break;
                    }
                }
                if (nums[mp[val].back()] == forbidden[mp[val].back()])
                    return -1;
                mp[val].pop_back();
            }
        }
        return swaps;
    }
};