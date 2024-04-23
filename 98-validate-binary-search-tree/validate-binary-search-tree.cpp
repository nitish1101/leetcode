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

/**
      5
    /  \
   2    6
 /  
1
  \ 
   3
*/

class Solution {
public:
    bool inorder(TreeNode* root, TreeNode* min, TreeNode* max)
    {
        if(!root)
            return true;
        if((!min || root->val > min->val) && (!max || root->val < max->val))
            return inorder(root->left,min,root) && inorder(root->right , root , max);
        return false;
    }
    bool isValidBST(TreeNode* root) {
        
        return inorder(root,NULL,NULL);
        
    }
};



