class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    bool dfs(int r, int c, int index, vector<vector<char>>& board, string& word) {
        if (index == word.length()) return true;
        
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }
        
        char temp = board[r][c];
        board[r][c] = '*'; 
        for (int i = 0; i < 4; i++) {
            int new_r = r + dr[i];
            int new_c = c + dc[i];
            if (dfs(new_r, new_c, index + 1, board, word)) {
                board[r][c] = temp; 
                return true;
            }
        }
                     
        board[r][c] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == word[0] && dfs(r, c, 0, board, word)) {
                    return true; 
                }
            }
        }
        
        return false;
    }
};
