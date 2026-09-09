#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> distArray(n, vector<int>(n, 1e9));
        q.push({1, {0, 0}});
        distArray[0][0] = 1;
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if (r == n - 1 && c == n - 1) {
                return d;
            }
            
            for(int i = 0; i < 8; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && d + 1 < distArray[nr][nc]){
                    distArray[nr][nc] = d + 1;
                    q.push({d + 1, {nr, nc}});
                }
            }
        }
        return -1;
    }
};