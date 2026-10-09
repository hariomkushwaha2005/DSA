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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        vector<TreeNode *> st;
        for (int num : nums)
        {
            TreeNode *node = new TreeNode(num);
            while (!st.empty() && st.back()->val < num)
            {
                TreeNode *curr = st.back();
                st.pop_back();
                if (!st.empty() && st.back()->val < num)
                {
                    st.back()->right = curr;
                }
                else
                {
                    node->left = curr;
                }
            }
            st.push_back(node);
        }
        while (st.size() > 1)
        {
            TreeNode *cur = st.back();
            st.pop_back();
            st.back()->right = cur;
        }
        return st.back();
    }
};