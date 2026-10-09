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
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *temp = head, *temp2 = nullptr, *temp3 = nullptr;
        int c = k;
        while (c > 1 && temp)
        {
            temp = temp->next;
            c--;
        }
        temp2 = temp->next;
        temp3 = head;
        while (temp2)
        {
            temp2 = temp2->next;
            temp3 = temp3->next;
        }
        swap(temp->val, temp3->val);
        return head;
    }
};