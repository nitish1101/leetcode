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
    int maxPathSum(TreeNode* root) {
        int best = INT_MIN;
        gain(root, best);
        return best;
    }

private:
    int gain(TreeNode* node, int& best) {
        if (!node) return 0;
        int left = max(0, gain(node->left, best));
        int right = max(0, gain(node->right, best));
        best = max(best, node->val + left + right);
        return node->val + max(left, right);
    }
};
