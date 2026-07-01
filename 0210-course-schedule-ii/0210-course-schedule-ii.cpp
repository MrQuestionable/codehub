class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n, 0);
        vector<int>ans;
 
        for(auto x: pre){
            int u = x[1];
            int v = x[0];
 
            indegree[v]++;
            adj[u].push_back(v);
        }
 
        queue<int>q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
 
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
 
            for(auto nbr: adj[u]){
                indegree[nbr]--;
 
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
 
        if(ans.size() != n) return {};
        return ans;
        
    }
};