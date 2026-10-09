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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) {
            slow = slow->next;
        }
        while (slow && slow->val == st.top()) {
            st.pop();
            slow = slow->next;
        }
        if (!st.empty())
            return false;
        return true;
    }
};