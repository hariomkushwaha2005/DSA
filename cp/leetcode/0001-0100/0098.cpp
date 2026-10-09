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
    bool eren(TreeNode *root, long long minn, long long maxx)
    {
        if (!root)
            return true;
        if (root->val <= minn || root->val >= maxx)
            return false;
        return eren(root->left, minn, root->val) && eren(root->right, root->val, maxx);
    }
    bool isValidBST(TreeNode *root)
    {
        return eren(root, LLONG_MIN, LLONG_MAX);
    }
};