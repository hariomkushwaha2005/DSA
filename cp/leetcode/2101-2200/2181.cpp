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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *ourhead = nullptr, *tail = nullptr, *node = head;
        while (node->next != nullptr)
        {
            node = node->next;
            int sum = 0;
            while (node->val != 0)
            {
                sum += node->val;
                node = node->next;
            }
            if (!ourhead)
            {
                ourhead = new ListNode(sum);
                tail = ourhead;
            }
            else
            {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
        }
        return ourhead;
    }
};