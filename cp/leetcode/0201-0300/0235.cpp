#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int a = min(p->val, q->val);
        int b = max(p->val, q->val);
        TreeNode *temp = root;
        while (temp)
        {
            int cur = temp->val;
            if (cur > a && cur > b)
                temp = temp->left;
            else if (cur < a && cur < b)
                temp = temp->right;
            else
                break;
        }
        return temp;
    }
};