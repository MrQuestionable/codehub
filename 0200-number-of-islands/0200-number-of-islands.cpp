class Solution {
public:
    int n, m;
    vector<vector<int>>directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
 
    void dfs(vector<vector<char>>&grid, vector<vector<int>>&vis, int x, int y){
        
        if(vis[x][y] == 1) return;
 
        vis[x][y] = 1;
 
        auto isSafe = [&](int u, int v){
            return u >= 0 && u < n && v >= 0 && v < m;
        };
 
        for(auto dir: directions){
 
            int x_ = x + dir[0];
            int y_ = y + dir[1];
 
            if(isSafe(x_, y_) && grid[x_][y_] == '1' && vis[x_][y_] == 0){
 
                dfs(grid, vis, x_, y_);
 
            }
 
        }
    }
 
    int numIslands(vector<vector<char>>& grid) {
 
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
 
        vector<vector<int>>vis(n, vector<int>(m, 0));
 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
 
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    dfs(grid, vis, i, j);
                    ans++;
 
                }
            }
        }
 
        return ans;
        
    }
};