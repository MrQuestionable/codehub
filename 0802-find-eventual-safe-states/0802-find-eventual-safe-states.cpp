class Solution {
public:
vector<int>safe;

    bool dfs(vector<vector<int>>& graph,vector<int>& pathVis,vector<int>&vis,int node){
        pathVis[node] = 1;
        vis[node]=1;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(!dfs(graph,pathVis,vis,it)){
                    safe[node] = 1;
                    return false;
                }
            }
            else if(pathVis[it]==1){
                pathVis[node] = 0;
                safe[node] = 1;
                return false;
            }
            else if(safe[it]==1){
                pathVis[node] = 0;
                safe[node] = 1;
                return false;
            }
        }
        pathVis[node] = 0;
        safe[node] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        safe.assign(n,0);
        vector<int>pathVis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(graph,pathVis,vis,i);
            }
        }
        vector<int>v;
        for(int i=0;i<n;i++){
            if(safe[i]==2){
                v.push_back(i);
            }
        }
        return v;
    }
};