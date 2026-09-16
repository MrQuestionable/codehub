class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        // 1. Build the full 2D DP table (LCS logic)
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // 2. Backtrack to generate the string
        string ans = "";
        int i = n, j = m;
        
        while(i > 0 && j > 0) {
            // Match found: Add once, move diagonally
            if(str1[i-1] == str2[j-1]) {
                ans += str1[i-1];
                i--;
                j--;
            } 
            // Move in the direction of the greater DP value
            else if(dp[i-1][j] > dp[i][j-1]) {
                ans += str1[i-1];
                i--; // Moved UP
            } 
            else {
                ans += str2[j-1];
                j--; // Moved LEFT
            }
        }
        
        // 3. Add any leftover characters from str1
        while(i > 0) {
            ans += str1[i-1];
            i--;
        }
        
        // 4. Add any leftover characters from str2
        while(j > 0) {
            ans += str2[j-1];
            j--;
        }
        
        // 5. We built it backwards, so reverse it
        reverse(ans.begin(), ans.end());
        return ans;
    }
};