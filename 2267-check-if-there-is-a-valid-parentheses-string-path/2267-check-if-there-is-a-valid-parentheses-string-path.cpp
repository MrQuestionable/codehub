class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if((m+n-1)%2!=0 || grid[0][0]==')'||grid[m-1][n-1]=='(')return false;
        vector<bitset<105>> dp(n);
        dp[0].set(1);
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(r==0 && c==0)continue;
                bitset<105> state;
                if (r > 0) state |= dp[c];     
                if (c > 0) state |= dp[c - 1]; 
                
                if (grid[r][c] == '(') {
                    dp[c] = state << 1; 
                } else {
                    dp[c] = state >> 1;
                }
            }
        }
    return dp[n-1].test(0);
    }
};
