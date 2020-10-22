/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int d = 1e5;
    void findmindepth(TreeNode* root, int val)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {   //cout<<val<<endl;
            d = min(d, val);
            return;
        }

        findmindepth(root->left, val + 1);
        findmindepth(root->right, val + 1);

    }
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;

        findmindepth(root, 1);

        return d;
    }
};