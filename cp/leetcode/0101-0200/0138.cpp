#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *nexty = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = nexty;
            temp = nexty;
        }
        temp = head;
        while (temp != nullptr)
        {
            if (temp->random)
            {
                Node *kaguya = temp->next;
                kaguya->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        Node *dummy = new Node(-1);
        Node *tail = dummy;
        temp = head;
        while (temp != nullptr)
        {
            tail->next = temp->next;
            tail = tail->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        Node *newhead = dummy->next;
        delete dummy;
        return newhead;
    }
};