#include <bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* head = nullptr;
        if (left->val <= right->val) {
            head = left;
            left = left->next;
            head->next = nullptr;
        } else {
            head = right;
            right = right->next;
            head->next = nullptr;
        }
        ListNode* tail = head;
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                ListNode* temp = left;
                left = left->next;
                temp->next = nullptr;
                tail->next = temp;
                tail = tail->next;
            } else {
                ListNode* temp = right;
                right = right->next;
                temp->next = nullptr;
                tail->next = temp;
                tail = tail->next;
            }
        }
        while (left != nullptr) {
            ListNode* temp = left;
            left = left->next;
            temp->next = nullptr;
            tail->next = temp;
            tail = tail->next;
        }
        while (right != nullptr) {
            ListNode* temp = right;
            right = right->next;
            temp->next = nullptr;
            tail->next = temp;
            tail = tail->next;
        }
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* middlenode = middle(head);
        ListNode* righthead = middlenode->next;
        middlenode->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(righthead);

        return merge(left, right);
    }
};