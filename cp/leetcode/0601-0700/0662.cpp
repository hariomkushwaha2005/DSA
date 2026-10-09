#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 right(right) {}
 };

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if (root)
            q.push({root, 0});
        int ans = 0;
        while (!q.empty()) {
            int n = q.size();
            int minn = INT_MAX, maxx = INT_MIN;
            int base = q.back().second;
            for (int i = 0; i < n; i++) {
                auto it = q.front();
                q.pop();
                int idx=it.second-base;
                minn = min(minn, idx);
                maxx = max(maxx, idx);
                if (it.first->left)
                    q.push({it.first->left, (idx<<1) + 1});
                if (it.first->right)
                    q.push({it.first->right, (idx<<1)});
            }
            ans = max(ans, maxx - minn + 1);
        }
        return ans;
    }
};