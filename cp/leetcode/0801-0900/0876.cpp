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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *mid = head;
        int cnt = 0;
        while (temp != nullptr)
        {
            cnt++;
            if (cnt % 2 == 0)
            {
                mid = mid->next;
            }
            temp = temp->next;
        }
        return mid;
    }
};