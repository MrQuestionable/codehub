class Solution {
public:
        int findUl(int x,vector<int>& parent){
        if(parent[x]==x)return x;
        return parent[x]=findUl(parent[x],parent);
    }

    void usets(int x, int y, vector<int>& parent, vector<int>& size){
        int xroot = findUl(x, parent);
        int yroot = findUl(y, parent);
        if(xroot == yroot) return;
        if(size[xroot] < size[yroot]) {
            parent[xroot] = yroot;
            size[yroot] += size[xroot];
        } 
        else {
            parent[yroot] = xroot;
            size[xroot] += size[yroot];
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> parent(n * n);
        vector<int> size(n * n, 1); 
        
        for(int i = 0; i < n * n; i++) parent[i] = i;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == 0) continue;
                
                for(int i = 0; i < 4; i++) {
                    int nr = r + delrow[i];
                    int nc = c + delcol[i];
                    
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        int node = r * n + c;
                        int adjNode = nr * n + nc;
                        usets(node, adjNode, parent, size);
                    }
                }
            }
        }
        
        int mx = 0;
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == 1) continue;
                
                unordered_set<int> uniqueRoots;
                
                for(int i = 0; i < 4; i++) {
                    int nr = r + delrow[i];
                    int nc = c + delcol[i];
                    
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        uniqueRoots.insert(findUl(nr * n + nc, parent));
                    }
                }
                
                int currentSize = 1;
                for(int root : uniqueRoots) {
                    currentSize += size[root];
                }
                mx = max(mx, currentSize);
            }
        }
        if (mx == 0) return n * n;
        
        return mx;
    }
};