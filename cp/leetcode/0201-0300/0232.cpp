#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
    stack<int> st, st1;

public:
    MyQueue() {}

    void push(int x) { st.push(x); }

    int pop()
    {
        if (st1.size() == 0)
        {
            while (!st.empty())
            {
                st1.push(st.top());
                st.pop();
            }
        }
        int x = st1.top();
        st1.pop();
        return x;
    }

    int peek()
    {
        if (st1.size() == 0)
        {
            while (!st.empty())
            {
                st1.push(st.top());
                st.pop();
            }
        }
        return st1.top();
    }

    bool empty() { return !(st.size() | st1.size()); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */