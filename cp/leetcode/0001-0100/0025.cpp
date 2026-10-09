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
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr, *temp = head;
        while (temp != nullptr)
        {
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode *getk(ListNode *temp, int k)
    {
        ListNode *ite = temp;
        int cnt = 1;
        while (cnt < k && ite != nullptr)
        {
            cnt++;
            ite = ite->next;
        }
        return ite;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *prev = dummy;
        while (prev->next != nullptr)
        {
            ListNode *temp = prev->next;
            ListNode *ite = getk(temp, k);
            if (ite == nullptr)
                break;
            ListNode *front = ite->next;
            ite->next = nullptr;
            reverse(temp);
            prev->next = ite;
            temp->next = front;
            prev = temp;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};