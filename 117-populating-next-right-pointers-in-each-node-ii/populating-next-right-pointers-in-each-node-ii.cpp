/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
    Node *cur, head(0);Node* x=root;
        while(root)
        {
            head.next = NULL;
            cur = &head;
            while(root)
            {
                if(root->left)
                {
                    cur->next = root->left;
                    cur = cur->next;
                }
                if(root->right)
                {
                    cur->next = root->right;
                    cur = cur->next;
                }
                root = root->next;
            }
            root = head.next;
        }
        return x;
    }
};