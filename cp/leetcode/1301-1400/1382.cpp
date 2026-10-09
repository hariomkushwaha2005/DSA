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
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<TreeNode *> nodes;
        eren(root, nodes);
        return mikasa(nodes, 0, nodes.size() - 1);
    }

private:
    void eren(TreeNode *root, vector<TreeNode *> &nodes)
    {
        if (!root)
            return;
        eren(root->left, nodes);
        nodes.push_back(root);
        eren(root->right, nodes);
    }
    TreeNode *mikasa(const vector<TreeNode *> &nodes, int i, int j)
    {
        if (i > j)
            return nullptr;
        int mid = i + (j - i) / 2;
        TreeNode *root = nodes[mid];
        root->left = mikasa(nodes, i, mid - 1);
        root->right = mikasa(nodes, mid + 1, j);
        return root;
    }
};