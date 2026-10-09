#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
private:
    void mikasa(Node *node, vector<int> &ans)
    {
        if (node == nullptr)
            return;
        for (auto &it : node->children)
        {
            mikasa(it, ans);
        }
        ans.push_back(node->val);
    }

public:
    vector<int> postorder(Node *root)
    {
        vector<int> ans;
        mikasa(root, ans);
        return ans;
    }
};