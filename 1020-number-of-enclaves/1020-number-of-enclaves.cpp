#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int delrow[], int delcol[]) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc}); 
                }
            }    
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int cnt = 0;
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int j = 0; j < m; j++) {
            if(!vis[0][j] && grid[0][j] == 1) 
                bfs(0, j, grid, vis, delrow, delcol);
            if(!vis[n - 1][j] && grid[n - 1][j] == 1) 
                bfs(n - 1, j, grid, vis, delrow, delcol);
        }
        
        for(int i = 0; i < n; i++) {
            if(!vis[i][0] && grid[i][0] == 1) 
                bfs(i, 0, grid, vis, delrow, delcol);
            if(!vis[i][m - 1] && grid[i][m - 1] == 1) 
                bfs(i, m - 1, grid, vis, delrow, delcol);
        }
        
        for(int i = 1; i < n - 1; i++){
            for(int j = 1; j < m - 1; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;    
    }
};