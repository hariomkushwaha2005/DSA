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
    TreeNode *del(TreeNode *temp)
    {
        if (temp->left)
        {
            TreeNode *root = temp->left;
            if (temp->right)
            {
                TreeNode *boba = temp->right;
                while (boba->left)
                {
                    boba = boba->left;
                }
                boba->left = root->right;
                root->right = temp->right;
            }
            delete temp;
            return root;
        }
        else if (temp->right)
        {
            TreeNode *root = temp->right;
            delete temp;
            return root;
        }
        else
        {
            delete temp;
            return nullptr;
        }
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        TreeNode *temp = root;
        if (temp && temp->val == key)
            return del(root);
        while (temp)
        {
            if (temp->val < key)
            {
                if (temp->right && temp->right->val == key)
                {
                    temp->right = del(temp->right);
                    return root;
                }
                temp = temp->right;
            }
            else
            {
                if (temp->left && temp->left->val == key)
                {
                    temp->left = del(temp->left);
                    return root;
                }
                temp = temp->left;
            }
        }
        return root;
    }
};