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
private:
    int mikasa(TreeNode *node, int low, int high)
    {
        if (!node)
            return 0;
        int ans = 0;
        if (node->val >= low)
            ans += mikasa(node->left, low, high);
        if (node->val <= high)
            ans += mikasa(node->right, low, high);
        if (node->val <= high && node->val >= low)
            ans += node->val;
        return ans;
    }

public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        return mikasa(root, low, high);
    }
};