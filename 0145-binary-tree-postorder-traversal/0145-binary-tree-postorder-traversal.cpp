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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>n;
        postOrder(root, n);
        return n;
    }
    void postOrder(TreeNode *head, vector<int>& n){
        if (head == nullptr) return;
        postOrder(head->left, n);
        postOrder(head->right, n);
        n.push_back(head->val);
    }

};