class Solution {
public:
    void rec(vector<vector<int>>& adj, vector<int>&color, int u, int curr, bool &ans){
 
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
    bool isBipartite(vector<vector<int>>& adj) {
 
        int n = adj.size();
        vector<int>color(n, -1);
        bool ans = true;
 
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                rec(adj, color, i, 0, ans);
            }
        }
        return ans;
    }
};