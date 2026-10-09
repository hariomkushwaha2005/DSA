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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        if (n == 0)
            return nullptr;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
        return build(inorder, 0, n - 1, postorder, 0, n - 1, mp);
    }
    TreeNode *build(vector<int> &in, int is, int ie, vector<int> &post, int ps,
                    int pe, unordered_map<int, int> &mp)
    {
        if (ps > pe || is > ie)
            return nullptr;
        TreeNode *root = new TreeNode(post[pe]);
        int inr = mp[root->val];
        int k = inr - is;
        root->left = build(in, is, inr - 1, post, ps, ps + k - 1, mp);
        root->right = build(in, inr + 1, ie, post, ps + k, pe - 1, mp);
        return root;
    }
};