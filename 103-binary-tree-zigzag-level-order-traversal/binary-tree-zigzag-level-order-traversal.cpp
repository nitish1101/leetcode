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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        int level=0;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int> v;
            while(n--)
            {
                TreeNode* e=q.front();
                q.pop();
                v.push_back(e->val);
                if(e->left)
                    q.push(e->left);
                if(e->right)
                    q.push(e->right);
            }
            if(level%2==0)
                ans.push_back(v);
            else {
                reverse(v.begin(),v.end());
                ans.push_back(v);
            }
            level++;
        }
        return ans;
    }
};