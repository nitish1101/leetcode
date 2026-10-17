/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> pos;
        for (int i = 0; i < (int)inorder.size(); ++i) pos[inorder[i]] = i;
        int pre = 0;
        return build(preorder, 0, (int)inorder.size() - 1, pos, pre);
    }

private:
    TreeNode* build(vector<int>& preorder, int lo, int hi,
                    unordered_map<int, int>& pos, int& pre) {
        if (lo > hi) return nullptr;
        int val = preorder[pre++];
        TreeNode* root = new TreeNode(val);
        int mid = pos[val];
        root->left = build(preorder, lo, mid - 1, pos, pre);
        root->right = build(preorder, mid + 1, hi, pos, pre);
        return root;
    }
};
