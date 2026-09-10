class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& it:times){
            int u=it[0],v=it[1],w=it[2];
            adj[u].push_back({v,w});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        queue<pair<int,int>> q;
        q.push({0,k});
        while(!q.empty()){
            int time=q.front().first;
            int node=q.front().second;
            q.pop();
            for(auto& [nbr,wt]:adj[node]){
                if(wt+time<dist[nbr]){
                    dist[nbr]=wt+time;
                    q.push({dist[nbr],nbr});
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};