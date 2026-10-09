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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *temp = head;
        int n = 1;
        while (temp->next != nullptr)
        {
            n++;
            temp = temp->next;
        }
        temp->next = head;
        int cnt = 0;
        k = k % n;
        while (cnt < n - k)
        {
            temp = temp->next;
            cnt++;
        }
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};