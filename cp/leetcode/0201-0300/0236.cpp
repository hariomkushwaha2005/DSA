#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool kaguya(TreeNode *root, TreeNode *p, vector<TreeNode *> &v)
    {
        if (!root)
            return false;
        v.push_back(root);
        if (root == p)
            return true;
        if (kaguya(root->left, p, v) || kaguya(root->right, p, v))
            return true;
        v.pop_back();
        return false;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> rp, rq;
        kaguya(root, p, rp);
        kaguya(root, q, rq);
        TreeNode *ans = nullptr;
        for (int i = 0; i < min(rp.size(), rq.size()); i++)
        {
            if (rp[i] != rq[i])
                break;
            ans = rp[i];
        }
        return ans;
    }
};