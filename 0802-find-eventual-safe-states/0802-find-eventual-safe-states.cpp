class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> ans;
        vector<vector<int>> adj(n);
        queue<int> q;
        vector<int> inorder(n,0);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                inorder[i]++;
            } 
        }
        for(int i=0;i<n;i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                inorder[it]--;
                if(inorder[it]==0)q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};