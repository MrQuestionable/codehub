class Solution {
public:
    void rec(unordered_map<int,vector<int>>&adj, vector<bool>&vis, int u){
 
        vis[u] = true;
 
        for(auto nbr: adj[u]){
 
            if(vis[nbr] == false){
                rec(adj, vis, nbr);
            }
        }
    }
 
    int findCircleNum(vector<vector<int>>& isConnected) {
 
        unordered_map<int,vector<int>>adj;
        int n = isConnected.size();
        int m = isConnected[0].size();
 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
 
                if(i == j) continue;
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
 
        int count = 0;
        vector<bool>vis(n, 0);
        for(int i = 0; i < n; i++){
            if(vis[i] == false){
                rec(adj, vis, i);
                count++;
            }
        }
 
        return count;
        
    }
};