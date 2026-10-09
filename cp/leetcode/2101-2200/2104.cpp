#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> NGE(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && v[i] >= v[st.top()])
                st.pop();
            if (!st.empty())
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> NSE(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && v[i] <= v[st.top()])
                st.pop();
            if (!st.empty())
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> PGE(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && v[i] > v[st.top()])
                st.pop();
            if (!st.empty())
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> PSE(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && v[i] < v[st.top()])
                st.pop();
            if (!st.empty())
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    long long maxsum(vector<int>& v) {
        int n = v.size();
        long long ans = 0;
        vector<int> nge = NGE(v);
        vector<int> pge = PGE(v);
        for (int i = 0; i < n; i++) {
            long long left = nge[i] - i;
            long long right = i - pge[i];
            ans += v[i] * left * right;
        }
        return ans;
    }
    long long minsum(vector<int>& v) {
        int n = v.size();
        long long ans = 0;
        vector<int> nse = NSE(v);
        vector<int> pse = PSE(v);
        for (int i = 0; i < n; i++) {
            long long left = nse[i] - i;
            long long right = i - pse[i];
            ans += v[i] * left * right;
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long mini = minsum(nums);
        long long maxi = maxsum(nums);
        return maxi - mini;
    }
};