#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    int key;
    StockSpanner()
    {
        key = -1;
        while (!st.empty())
            st.pop();
    }
    int next(int price)
    {
        key++;
        while (!st.empty() && st.top().first <= price)
            st.pop();
        int ans = key - (st.empty() ? -1 : st.top().second);
        st.push({price, key});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */