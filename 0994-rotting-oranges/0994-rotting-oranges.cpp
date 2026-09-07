#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int,int>, int>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else {
                    vis[i][j] = 0;
                }
            }
        }
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int ro = q.front().first.first;
            int co = q.front().first.second;
            int t = q.front().second;
            cnt = max(t, cnt);
            q.pop();
            for(int i = 0; i < 4; i++){
                int nrow = ro + drow[i];
                int ncol = co + dcol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && 
                   grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return cnt;
    }
};