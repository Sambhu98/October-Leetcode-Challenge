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
    //using inoder traversal
    // where the nodes are kinda sorted
    void RecoverTree(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& end) {
        if (!root) return;
        RecoverTree(root->left, prev, first, end);
        if (prev) {
            if (root->val < prev->val) {
                if (!first) {
                    first = prev;
                }
                end = root;
            }
        }
        prev = root;
        RecoverTree(root->right, prev, first, end);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr, *first = nullptr, *end = nullptr;
        RecoverTree(root, prev, first, end);
        swap(first->val, end->val);
        return;
    }
};