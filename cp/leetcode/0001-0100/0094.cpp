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
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> v;
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->left == nullptr)
            {
                v.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                TreeNode *temp = cur->left;
                while (temp->right && temp->right != cur)
                    temp = temp->right;
                if (!temp->right)
                {
                    temp->right = cur;
                    cur = cur->left;
                }
                else
                {
                    v.push_back(cur->val);
                    temp->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return v;
    }
};