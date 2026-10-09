#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
private:
    TreeNode *inOrder(TreeNode *node, TreeNode *parent)
    {
        TreeNode *head = node;
        if (node->left)
        {
            head = inOrder(node->left, node);
        }
        node->left = nullptr;
        TreeNode *next = parent;
        if (node->right)
        {
            next = inOrder(node->right, parent);
        }
        node->right = next;
        return head;
    }

public:
    TreeNode *increasingBST(TreeNode *root) { return inOrder(root, nullptr); }
};