#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<TreeNode *, TreeNode *> mp;
        queue<TreeNode *> q;
        if (root)
            q.push(root);
        unordered_set<TreeNode *> v;
        TreeNode *st = nullptr;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                {
                    mp[node->left] = node;
                    q.push(node->left);
                }
                if (node->right)
                {
                    mp[node->right] = node;
                    q.push(node->right);
                }
                if (node->val == start)
                    st = node;
            }
        }
        q.push(st);
        int cnt = 0;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left && !v.count(node->left))
                {
                    v.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && !v.count(node->right))
                {
                    v.insert(node->right);
                    q.push(node->right);
                }
                if (mp.count(node) && !v.count(mp[node]))
                {
                    q.push(mp[node]);
                }
                v.insert(node);
            }
            cnt++;
        }
        return cnt - 1;
    }
};