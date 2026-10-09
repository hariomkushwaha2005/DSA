#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        if (n == 0)
            return nullptr;
        ListNode *head = nullptr, *tail = nullptr;
        int idx = 0;
        while (1)
        {
            for (int i = 0; i < n; ++i)
            {
                if (!lists[idx])
                {
                    idx = i;
                    continue;
                }
                if (lists[i] && lists[i]->val < lists[idx]->val)
                {
                    idx = i;
                }
            }
            if (!head)
                head = tail = lists[idx];
            else
            {
                tail->next = lists[idx];
                tail = tail->next;
            }
            if (!lists[idx])
                break;
            lists[idx] = lists[idx]->next;
        }
        return head;
    }
};