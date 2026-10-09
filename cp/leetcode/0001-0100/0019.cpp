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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr || head->next == nullptr)
        {
            delete head;
            return nullptr;
        }
        ListNode *front = head, *temp = head;
        for (int i = 0; i < n; i++)
        {
            front = front->next;
        }
        ListNode *prev = nullptr;
        while (front != nullptr)
        {
            front = front->next;
            prev = temp;
            temp = temp->next;
        }
        if (prev == nullptr)
        {
            prev = head;
            head = head->next;
            prev->next = nullptr;
            delete prev;
            return head;
        }
        prev->next = temp->next;
        temp->next = nullptr;
        delete temp;
        return head;
    }
};