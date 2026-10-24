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
    int rob(TreeNode* root) {
        auto [take, skip] = dfs(root);
        return max(take, skip);
    }

private:
    // {best sum robbing this node, best sum not robbing this node}
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto [lt, ls] = dfs(node->left);
        auto [rt, rs] = dfs(node->right);
        return {node->val + ls + rs, max(lt, ls) + max(rt, rs)};
    }
};
