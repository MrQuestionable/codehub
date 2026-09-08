class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<int>> &vis,int row,int col,int delrow[],int delcol[]){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int nr=q.front().first;
            int nc=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int ro=nr+delrow[i];
                int co=nc+delcol[i];
                if(ro>=0 && co>=0 && ro<n && co<m && !vis[ro][co] && grid[ro][co]=='1'){
                    vis[ro][co]=1;
                    q.push({ro,co});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                cnt++;
                bfs(grid,vis,i,j,delrow,delcol);
                }
            }
        }
    return cnt;    
    }
};