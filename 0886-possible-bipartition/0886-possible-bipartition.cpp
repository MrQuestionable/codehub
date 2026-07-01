class Solution {
public:
    void rec(unordered_map<int,vector<int>>& adj, vector<int>&color, int u, int curr, bool &ans){
 
        if(ans == false) return;
        color[u] = curr;
 
        for(auto nbr: adj[u]){
            if(color[nbr] == -1){
                rec(adj, color, nbr, 1 - curr, ans);
            }
            else if(color[nbr] == color[u]){
                ans = false;
                return;
            }
        }
    }
 
    bool possibleBipartition(int n, vector<vector<int>>& edges) {
        vector<int>color(n + 1, -1);
        bool ans = true;
 
        unordered_map<int, vector<int>>adj;
        for(auto x: edges){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                rec(adj, color, i, 0, ans);
            }
        }
        return ans;
        
    }
};