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
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *node = head;
        while (node->next)
        {
            ListNode *temp = node->next;
            node->next = new ListNode(__gcd(node->val, temp->val), temp);
            node = temp;
        }
        return head;
    }
};