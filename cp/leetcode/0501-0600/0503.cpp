#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = 0, maxx = nums[0];
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > maxx)
            {
                maxx = nums[i];
                maxi = i;
            }
        }
        int i = maxi;
        vector<int> ans(n, 0);
        ans[i] = -1;
        i = (i + n - 1) % n;
        stack<int> st;
        st.push(maxx);
        while (ans[i] != -1)
        {
            while (!st.empty() && st.top() <= nums[i])
            {
                st.pop();
            }
            if (!st.empty())
                ans[i] = st.top();
            else
                ans[i] = -1;
            st.push(nums[i]);
            i = (i + n - 1) % n;
        }
        return ans;
    }
};