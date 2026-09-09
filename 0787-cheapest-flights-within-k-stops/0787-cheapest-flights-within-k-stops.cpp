class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>> q;
        vector<vector<pair<int,int>>> adj(n);
        vector<int> dis(n,1e9);
        for(auto it:flights)adj[it[0]].push_back({it[1],it[2]});
        q.push({0,{src,0}});
        dis[src]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int cost=it.second.second;
            int node=it.second.first;
            int stops=it.first;
            if(stops>k)continue;
            for(auto iter:adj[node]){
                int adjnode=iter.first;
                int edgewt=iter.second;
                if(cost+edgewt<dis[adjnode] && stops<=k){
                    dis[adjnode]=cost+edgewt;
                    q.push({stops+1,{adjnode,cost+edgewt}});
                }
            }
        }
        if(dis[dst]==1e9)return -1;
        else return dis[dst];
    }
};