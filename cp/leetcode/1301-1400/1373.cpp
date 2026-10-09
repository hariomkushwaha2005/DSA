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
class mikasa
{
public:
    int maxx, minn, sum;
    mikasa(int maxx, int minn, int sum)
    {
        this->maxx = maxx;
        this->minn = minn;
        this->sum = sum;
    }
};
class Solution
{
private:
    int maxsum;
    mikasa eren(TreeNode *root)
    {
        if (!root)
            return mikasa(INT_MIN, INT_MAX, 0);
        mikasa left = eren(root->left);
        mikasa right = eren(root->right);
        if (left.maxx < root->val && right.minn > root->val)
        {
            int cursum = root->val + left.sum + right.sum;
            maxsum = max(maxsum, cursum);
            return mikasa(max(right.maxx, root->val), min(left.minn, root->val),
                          cursum);
        }
        return mikasa(INT_MAX, INT_MIN, 0);
    }

public:
    int maxSumBST(TreeNode *root)
    {
        maxsum = 0;
        eren(root);
        return maxsum;
    }
};