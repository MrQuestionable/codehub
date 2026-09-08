class Solution {
public:
 int n, m;
    void dfs(vector<vector<int>>& board, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m) return;
        if (board[i][j] != 1) return;   
        board[i][j] = 2;                 
        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }
    int numEnclaves(vector<vector<int>>& board) {
         n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            dfs(board, i, 0);       
            dfs(board, i, m - 1);   
        }
        for (int j = 0; j < m; j++) {
            dfs(board, 0, j);      
            dfs(board, n - 1, j);   
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1) count++;   
               
            }
        }
        return count;
    }
};