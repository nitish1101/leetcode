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
    TreeNode* invertTree(TreeNode* root) {
        if(root)
        {
            TreeNode* tmp=root->left;
            root->left=root->right;
            root->right=tmp;
            if(root->left)
                invertTree(root->left);
            if(root->right)
                invertTree(root->right);
        }
        
        return root;
    }

    bool checkId(TreeNode* a, TreeNode* b)
    {
        if(a==NULL && b==NULL)
            return true;
        if(a!=NULL && b!=NULL)
        {
            if(a->val==b->val && checkId(a->left,b->left) && checkId(a->right,b->right))
                return true;
        }
        return false;
        
    }

    bool isSymmetric(TreeNode* root) {
        root->left=invertTree(root->left);
        TreeNode* a=root->left;
        TreeNode* b=root->right;

        return checkId(a,b);



    }
};