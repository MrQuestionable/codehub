class Solution {
public:
    #define p pair<int,int>
    int networkDelayTime(vector<vector<int>>& edges, int V, int src) {
 
         unordered_map<int,vector<p>>adj;
         src = src - 1;
        for(auto x: edges){
            int u = x[0] - 1;
            int v = x[1] - 1;
            int wt = x[2];
            
            adj[u].push_back({v, wt});
            // adj[v].push_back({u, wt});
        }
        
        priority_queue<p, vector<p>, greater<p>>pq;
        vector<int>ans(V, INT_MAX);
        ans[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int u = pq.top().second;
            int first_dist = pq.top().first;
            pq.pop();
            
            for(auto nbr: adj[u]){
                int v = nbr.first;
                int sec_dist = nbr.second;
                int total = first_dist + sec_dist;
                
                if(total < ans[v]){
                    ans[v] = total;
                    pq.push({total, v});
                }
            }
        }
 
        int res = 0;
        for(auto x: ans) {
            res = max(res, x);
        }
 
        if(res == INT_MAX) return -1;
        return res;
        
    }
};