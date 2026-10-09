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
    int kaguya(TreeNode *root, int &ans)
    {
        if (root == nullptr)
            return 0;
        int a = kaguya(root->left, ans);
        int b = kaguya(root->right, ans);
        ans = max(ans, a + b);
        return max(a, b) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        int a = kaguya(root, ans);
        return ans;
    }
};