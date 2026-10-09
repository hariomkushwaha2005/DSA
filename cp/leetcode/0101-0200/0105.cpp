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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
        return build(preorder, 0, n - 1, inorder, 0, n - 1, mp);
    }
    TreeNode *build(vector<int> &pre, int ps, int pe, vector<int> &in, int is, int ie, unordered_map<int, int> &mp)
    {
        if (ps > pe || is > ie)
            return nullptr;
        TreeNode *root = new TreeNode(pre[ps]);
        int inr = mp[root->val];
        int k = inr - is;
        root->left = build(pre, ps + 1, ps + k, in, is, inr - 1, mp);
        root->right = build(pre, ps + k + 1, pe, in, inr + 1, ie, mp);
        return root;
    }
};