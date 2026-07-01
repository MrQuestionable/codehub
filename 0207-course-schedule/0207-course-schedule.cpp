class Solution {
public:
    void rec(unordered_map<int,vector<int>>&adj, vector<bool>&vis, vector<bool>&inrec, bool &ans, int u){
 
        if(ans == false) return;
        vis[u] = true;
        inrec[u] = true;
 
        for(auto nbr: adj[u]){
 
            if(vis[nbr] == false){
                rec(adj, vis, inrec, ans, nbr);
            }
            else if(inrec[nbr] == true){
                ans = false;
                return;
            }
        }
 
        inrec[u] = false;
    }
 
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
 
        vector<bool>vis(n, false);
        vector<bool>inrec(n, false);
        bool ans = true;
 
        unordered_map<int,vector<int>>adj;
 
        for(auto x: prerequisites){
            int u = x[0];
            int v = x[1];
 
            adj[u].push_back(v);
        }
 
        for(int i = 0; i < n; i++){
            if(vis[i] == false){
                rec(adj, vis, inrec, ans, i);
            }
        }
 
        return ans;
        
    }
};