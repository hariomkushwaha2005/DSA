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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return head;

        ListNode *oddt = head, *oddh = head, *event = head->next,
                 *evenh = head->next, *temp = evenh->next;

        while (temp)
        {
            oddt->next = temp;
            temp = temp->next;
            oddt = oddt->next;

            if (!temp)
                break;

            event->next = temp;
            temp = temp->next;
            event = event->next;
        }

        oddt->next = evenh;
        event->next = nullptr;
        return oddh;
    }
};