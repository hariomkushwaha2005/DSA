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
public:
    int pre(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int a = pre(root->left);
        int b = pre(root->right);
        if (a == -1 || b == -1)
            return -1;
        if (abs(a - b) > 1)
            return -1;
        return 1 + max(a, b);
    }
    bool isBalanced(TreeNode *root)
    {
        if (pre(root) == -1)
            return false;
        return true;
    }
};