#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s;
        queue<TreeNode *> q;
        if (root)
            q.push(root);
        while (!q.empty())
        {
            root = q.front();
            q.pop();
            if (root == nullptr)
                s += "#,";
            else
            {
                s += to_string(root->val);
                s += ',';
                q.push(root->left);
                q.push(root->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return nullptr;
        stringstream ss(data);
        string s;
        getline(ss, s, ',');
        if (s == "#")
            return {};
        TreeNode *root = new TreeNode(stoi(s));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (getline(ss, s, ',') && s != "#")
            {
                temp->left = new TreeNode(stoi(s));
                q.push(temp->left);
            }
            if (getline(ss, s, ',') && s != "#")
            {
                temp->right = new TreeNode(stoi(s));
                q.push(temp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));