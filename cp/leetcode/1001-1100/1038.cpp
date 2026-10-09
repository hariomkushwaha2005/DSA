
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
    TreeNode *bstToGst(TreeNode *root)
    {
        TreeNode *node = root;
        int sum = 0;
        while (node != nullptr)
        {
            if (!node->right)
            {
                node->val += sum;
                sum = node->val;
                node = node->left;
            }
            else
            {
                TreeNode *cur = node->right;
                while (cur->left != nullptr && cur->left != node)
                {
                    cur = cur->left;
                }
                if (!cur->left)
                {
                    cur->left = node;
                    node = node->right;
                }
                else
                {
                    cur->left = nullptr;
                    node->val += sum;
                    sum = node->val;
                    node = node->left;
                }
            }
        }
        return root;
    }
};