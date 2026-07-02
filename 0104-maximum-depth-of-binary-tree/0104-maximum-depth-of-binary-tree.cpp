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
    int rec(TreeNode* root){
        if(root == nullptr) return 0;

        int lh = rec(root->left);
        int rh = rec(root->right);

        return 1 + max(lh, rh);
    } 
    int maxDepth(TreeNode* root) {
        return rec(root);
    }
};