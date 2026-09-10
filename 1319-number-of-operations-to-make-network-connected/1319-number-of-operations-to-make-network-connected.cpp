class Solution {
public:
    int findUl(int x,vector<int>& parent){
        if(parent[x]==x)return x;
        return parent[x]=findUl(parent[x],parent);
    }

    void usets(int x,int y,vector<int>& parent,vector<int>& rank){
        int xroot=findUl(x,parent);
        int yroot=findUl(y,parent);
        if(xroot==yroot)return;
        if(rank[xroot]<rank[yroot])parent[xroot]=yroot;
        else if(rank[xroot]>rank[yroot])parent[yroot]=xroot;
        else{
            parent[yroot]=xroot;
            rank[xroot]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        vector<int> parent(n);
        for(int i=0;i<n;i++)parent[i]=i;
        vector<int> rank(n,0);
        int compo=n;
        for(auto& it:connections){
            int u=it[0];
            int v=it[1];
            if(findUl(u,parent)!=findUl(v,parent)){
                usets(u,v,parent,rank);
                compo--;     
            }        
        }
    return compo-1;    
    }
};