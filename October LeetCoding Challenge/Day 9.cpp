/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int pos;
    string encode(TreeNode* root)
    {
        if (root == NULL)
            return "_";

        string r = "";
        r += to_string(root->val);
        r += '.';
        r += encode(root->left);
        r += encode(root->right);

        return r;
    }
    TreeNode* decode(string ans)
    {
        if (pos >= ans.size())
            return NULL;

        if (ans[pos] == '_')
        {return NULL;}

        TreeNode *r = new TreeNode();
        string num = "";

        while (ans[pos] != '.')
        {   num += ans[pos];
            pos++;
        }

        r->val = stoi(num);
        ++pos;
        r->left = decode(ans);
        ++pos;
        r->right = decode(ans);
        return r;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = encode(root);
        //cout<<ans<<endl;
        return ans ;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        pos = 0;
        return decode(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;