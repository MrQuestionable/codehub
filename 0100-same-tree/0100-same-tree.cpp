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
    bool rec(TreeNode* p, TreeNode* q){
        if(p==nullptr && q == nullptr) return true;
        if(p==nullptr || q == nullptr) return false;

        if(p->val != q->val) return false;
        int left= rec(p->left, q->left);
        int right= rec(p->right, q-> right);

        return left && right;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return rec(p,q);
    }
};