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
    void kaguya(TreeNode *root, string s, vector<string> &ans)
    {
        s = s + "->" + to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(s);
            return;
        }
        if (root->left)
            kaguya(root->left, s, ans);
        if (root->right)
            kaguya(root->right, s, ans);
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (!root)
            return {};
        vector<string> ans;
        string s = to_string(root->val);
        if (root->left)
            kaguya(root->left, s, ans);
        if (root->right)
            kaguya(root->right, s, ans);
        if (!root->left && !root->right)
            ans.push_back(s);
        return ans;
    }
};