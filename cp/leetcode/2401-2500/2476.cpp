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
    void inorder(TreeNode *root, vector<int> &v)
    {
        if (!root)
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    vector<int> bomb(vector<int> &v, int x)
    {
        int ceil = -1, floor = -1;
        int l = 0, r = v.size() - 1;
        while (l <= r)
        {
            int mid = (l + (r - l) / 2);
            if (v[mid] == x)
            {
                floor = x;
                ceil = x;
                break;
            }
            else if (v[mid] < x)
            {
                floor = v[mid];
                l = mid + 1;
            }
            else
            {
                ceil = v[mid];
                r = mid - 1;
            }
        }
        return {floor, ceil};
    }
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries)
    {
        vector<vector<int>> ans;
        vector<int> v;
        inorder(root, v);
        for (int i = 0; i < queries.size(); i++)
        {
            ans.push_back(bomb(v, queries[i]));
        }
        return ans;
    }
};