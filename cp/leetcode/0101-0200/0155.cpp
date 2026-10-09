#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<long long> st;
    long long minn;

public:
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            minn = val;
            st.push(val);
        } else if (val > minn)
            st.push(val);
        else {
            long long f = val;
            st.push(2 * f - minn);
            minn = val;
        }
    }

    void pop() {
        if (st.empty())
            return;
        long long x = st.top();
        st.pop();
        if (x < minn) {
            minn = 2 * minn - x;
        }
    }

    int top() {
        if (st.empty())
            return -1;
        if (st.top() < minn)
            return minn;
        else
            return st.top();
    }

    int getMin() { return minn; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */