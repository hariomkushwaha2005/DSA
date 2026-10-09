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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        queue<pair<int, TreeNode *>> q;
        q.push({0, root});
        map<int, vector<int>> mp;
        while (!q.empty())
        {
            int size = q.size();
            unordered_map<int, vector<int>> loc;
            for (int i = 0; i < size; i++)
            {
                pair<int, TreeNode *> temp = q.front();
                if (loc.count(temp.first))
                    loc[temp.first].push_back(temp.second->val);
                else
                    loc[temp.first] = {temp.second->val};
                q.pop();
                if (temp.second->left)
                    q.push({temp.first - 1, temp.second->left});
                if (temp.second->right)
                    q.push({temp.first + 1, temp.second->right});
            }
            for (auto it : loc)
            {
                sort(it.second.begin(), it.second.end());
                if (mp.count(it.first))
                {
                    for (int i = 0; i < it.second.size(); i++)
                    {
                        mp[it.first].push_back(it.second[i]);
                    }
                }
                else
                {
                    mp[it.first] = it.second;
                }
            }
        }
        vector<vector<int>> ans;
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};