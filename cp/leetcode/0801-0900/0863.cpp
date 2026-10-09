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
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> mp;
        queue<TreeNode *> q;
        unordered_map<TreeNode *, bool> v;
        if (root)
        {
            q.push(root);
            v[root] = true;
        }
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left)
                {
                    mp[temp->left] = temp;
                    q.push(temp->left);
                    v[temp->left] = true;
                }
                if (temp->right)
                {
                    mp[temp->right] = temp;
                    q.push(temp->right);
                    v[temp->right] = true;
                }
            }
        }
        q.push(target);
        int dist = 0;
        while (dist < k)
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left && v[temp->left])
                {
                    q.push(temp->left);
                    v[temp->left] = false;
                }
                if (temp->right && v[temp->right])
                {
                    q.push(temp->right);
                    v[temp->right] = false;
                }
                if (mp.count(temp) && v[mp[temp]])
                {
                    q.push(mp[temp]);
                }
                v[temp] = false;
            }
            dist++;
        }
        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};