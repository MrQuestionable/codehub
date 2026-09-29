class Solution {
public:
    bool f(int r, int c, int balance, vector<vector<vector<int>>>& dp, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Out of bounds check
        if (r >= m || c >= n) return false;
        
        // Track the bracket balance
        if (grid[r][c] == '(') balance++;
        else balance--;
        
        // If closed brackets exceed open brackets, it's invalid
        if (balance < 0 || balance >= dp[0][0].size()) return false; 
        
        // Destination reached: check if all brackets are perfectly matched
        if (r == m - 1 && c == n - 1) {
            return balance == 0;
        }
        
        // Fix: Use integer -1 instead of a string
        if (dp[r][c][balance] != -1) return dp[r][c][balance];
        
        bool down = f(r + 1, c, balance, dp, grid);
        bool right = f(r, c + 1, balance, dp, grid);
        
        return dp[r][c][balance] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Quick pruning optimizations
        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;
        
        int max_balance = (m + n) / 2;
        
        // Fix: Initialize the 3D int vector with the integer -1
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(max_balance + 1, -1)));
        
        return f(0, 0, 0, dp, grid);
    }
};
