#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *scout(vector<int> &pre, int &i, int bound)
    {
        if (i == pre.size() || pre[i] > bound)
            return nullptr;
        TreeNode *root = new TreeNode(pre[i++]);
        root->left = scout(pre, i, root->val);
        root->right = scout(pre, i, bound);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return scout(preorder, i, INT_MAX);
    }
};