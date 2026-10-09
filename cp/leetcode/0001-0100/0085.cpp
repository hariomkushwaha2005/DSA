#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int histo(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (st.empty() || arr[st.top()] <= arr[i])
                st.push(i);
            else
            {
                while (!st.empty() && arr[st.top()] > arr[i])
                {
                    int x = st.top();
                    st.pop();
                    int width = st.empty() ? i : i - st.top() - 1;
                    ans = max(ans, arr[x] * width);
                }
                st.push(i);
            }
        }
        while (!st.empty())
        {
            int x = st.top();
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            ans = max(ans, arr[x] * width);
        }
        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    dp[j]++;
                else
                    dp[j] = 0;
            }
            ans = max(ans, histo(dp));
        }
        return ans;
    }
};