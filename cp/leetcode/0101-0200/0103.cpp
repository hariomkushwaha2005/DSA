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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ans;
        bool kei = 0;
        while (!q.empty())
        {
            vector<int> a;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
                a.push_back(temp->val);
            }
            if (!kei)
            {
                kei = 1;
                ans.push_back(a);
            }
            else
            {
                kei = 0;
                reverse(a.begin(), a.end());
                ans.push_back(a);
            }
        }
        return ans;
    }
};