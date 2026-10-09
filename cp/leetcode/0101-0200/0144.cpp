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
    vector<int> preorderTraversal(TreeNode *root)
    {
        TreeNode *cur = root;
        vector<int> v;
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
                {
                    temp = temp->right;
                }
                if (temp->right == nullptr)
                {
                    temp->right = cur;
                    v.push_back(cur->val);
                    cur = cur->left;
                }
                else
                {
                    temp->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return v;
    }
};