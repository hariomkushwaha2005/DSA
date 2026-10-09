#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int N = tasks.size();
        vector<int> v(26);
        for (int i = 0; i < N; i++) {
            v[tasks[i] - 'A']++;
        }
        priority_queue<int> pq;
        for (auto it : v) {
            if (it > 0)
                pq.push(it);
        }
        int ans = 0;
        while (!pq.empty()) {
            stack<int> rem;
            int a = 0;
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    rem.push(pq.top() - 1);
                    pq.pop();
                    a++;
                } else
                    break;
            }
            while (!rem.empty()) {
                if (rem.top() > 0)
                    pq.push(rem.top());
                rem.pop();
            }
            if (pq.empty())
                ans += a;
            else
                ans += (n + 1);
        }
        return ans;
    }
};