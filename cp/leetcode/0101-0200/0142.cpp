#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        int flag = 0;
        while (fast != nullptr && fast->next != nullptr)
        {
            if (flag == 0)
            {
                fast = fast->next->next;
                slow = slow->next;
                if (slow == fast)
                {
                    flag = 1;
                    slow = head;
                }
            }
            else
            {
                if (slow == fast)
                    return slow;
                slow = slow->next;
                fast = fast->next;
            }
        }
        return nullptr;
    }
};