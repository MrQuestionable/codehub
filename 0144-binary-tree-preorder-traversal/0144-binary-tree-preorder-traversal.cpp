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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL ) return ans;
        stack<TreeNode*> st; 
        st.push(root);
        while(!st.empty()){
            TreeNode* it = st.top();
            st.pop();
            ans.push_back(it->val);
            if(it->right != NULL) st.push(it->right);
            if(it->left  != NULL) st.push(it->left);
        }   
        return ans ;                    
    }
};