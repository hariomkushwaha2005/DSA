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
    unordered_map<string, int> mp;
    vector<TreeNode *> ans;
    string help(TreeNode *root)
    {
        if (!root)
            return "";
        string cur = to_string(root->val) + ',' + help(root->left) + ',' +
                     help(root->right);
        mp[cur]++;
        if (mp[cur] == 2)
            ans.push_back(root);
        return cur;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        help(root);
        return ans;
    }
};