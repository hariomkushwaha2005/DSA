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

class BSTIterator
{
private:
    stack<TreeNode *> st;
    bool reverse;
    void pushall(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            if (reverse)
                root = root->left;
            else
                root = root->right;
        }
    }

public:
    BSTIterator(TreeNode *root, bool isreverse) : reverse(isreverse)
    {
        pushall(root);
    }

    int next()
    {
        TreeNode *root = st.top();
        st.pop();
        if (reverse)
            pushall(root->right);
        else
            pushall(root->left);
        return root->val;
    }
};
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        BSTIterator l(root, true);
        BSTIterator r(root, false);

        int i = l.next();
        int j = r.next();

        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};