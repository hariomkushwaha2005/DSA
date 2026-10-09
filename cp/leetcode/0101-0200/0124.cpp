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
    struct S
    {
        int tot;
        int sum;
        S(int tot, int sum)
        {
            this->tot = tot;
            this->sum = sum;
        }
    };

    int INF = -1e9;

    S help(TreeNode *root)
    {
        if (!root)
            return {INF, INF};

        S s1 = help(root->left);
        S s2 = help(root->right);

        int sum = max({s1.sum, s2.sum, 0}) + root->val;
        int tot = max({s1.tot, s2.tot, max({s1.sum, s2.sum, s1.sum + s2.sum, 0}) + root->val});
        return {tot, sum};
    }

    int maxPathSum(TreeNode *root)
    {
        S ans = help(root);
        return ans.tot;
    }
};