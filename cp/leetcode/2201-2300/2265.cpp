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
    int averageOfSubtree(TreeNode *root)
    {
        int ans = 0;
        mikasa(root, ans);
        return ans;
    }

private:
    pair<int, int> mikasa(TreeNode *root, int &ans)
    {
        if (!root)
            return {0, 0};
        pair<int, int> left = mikasa(root->left, ans);
        pair<int, int> right = mikasa(root->right, ans);
        int sum = root->val + left.first + right.first;
        int cnt = 1 + left.second + right.second;
        ans += root->val == (sum / cnt);
        return {sum, cnt};
    }
};