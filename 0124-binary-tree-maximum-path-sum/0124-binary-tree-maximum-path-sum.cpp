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
    int find(TreeNode* root, int &maxsum){
        if(root==NULL)return 0;
        int lh=max(0,find(root->left,maxsum));
        int rh=max(0,find(root->right,maxsum));
        maxsum=max(maxsum,lh+rh+root->val);
        return max(lh,rh)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        find(root,maxsum);
        return maxsum;
    }
};