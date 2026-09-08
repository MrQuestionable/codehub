#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis, int delrow[], int delcol[]) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        
        int n = board.size();
        int m = board[0].size();
        
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && board[nr][nc] == 'O') {
                    vis[nr][nc] = 1;
                    q.push({nr, nc}); 
                }
            }    
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++) {
            if(!vis[0][j] && board[0][j] == 'O') 
                bfs(0, j, board, vis, delrow, delcol);
            if(!vis[n - 1][j] && board[n - 1][j] == 'O') 
                bfs(n - 1, j, board, vis, delrow, delcol);
        }
        for(int i = 0; i < n; i++) {
            if(!vis[i][0] && board[i][0] == 'O') 
                bfs(i, 0, board, vis, delrow, delcol);
            if(!vis[i][m - 1] && board[i][m - 1] == 'O') 
                bfs(i, m - 1, board, vis, delrow, delcol);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};