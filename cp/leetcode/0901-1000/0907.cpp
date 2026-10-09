#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        long long x = 1e9 + 7;
        int n = arr.size();
        stack<int> st;
        vector<int> next(n, n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                next[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        vector<int> prev(n, -1);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                prev[i] = st.top();
            }
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int left = i - prev[i];
            int right = next[i] - i;
            ans = (ans + (((long long)arr[i] * left * right) % x)) % x;
        }
        return ans;
    }
};