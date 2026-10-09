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
    bool kaguya(TreeNode *lembo, TreeNode *rembo)
    {
        if (lembo == nullptr && rembo == nullptr)
            return true;
        if (lembo == nullptr || rembo == nullptr)
            return false;
        return ((lembo->val == rembo->val) &&
                kaguya(lembo->left, rembo->right) &&
                kaguya(lembo->right, rembo->left));
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root)
        {
            return kaguya(root->left, root->right);
        }
        return true;
    }
};