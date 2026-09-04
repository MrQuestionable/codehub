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
    bool isValidBST(TreeNode* root) {
       TreeNode* curr=root;
       TreeNode* prenode=nullptr;
       bool isvalid=true;
       while(curr!=NULL){
        if(curr->left==NULL){
            if (prenode != nullptr && prenode->val >= curr->val)isvalid = false;
            prenode = curr;
            curr=curr->right;
        }
        else{
            TreeNode* prev=curr->left;
            while(prev->right && prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                if(prenode!=nullptr && prenode->val>=curr->val)isvalid=false;
                prenode=curr;
                curr=curr->right;
            }
        }
       } 
    return isvalid;   
    }
};