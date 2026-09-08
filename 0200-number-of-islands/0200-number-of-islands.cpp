class Solution {
public:
   void dfs(int i,int j,vector<vector<char>>& grid){
     int n=grid.size();
        int m=grid[0].size();

    grid[i][j]='#';
    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};
    for(int k=0;k<4;k++){
        int nr=dr[k]+i;
        int nc=dc[k]+j;
        if(nr<n && nr>=0 && nc<m && nc>=0 && grid[nr][nc]=='1'){
            dfs(nr,nc,grid);
        }
    }
   }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
         dfs(i,j,grid);
         cnt++;
                }
            }
        }
        return cnt;

        
    }
};