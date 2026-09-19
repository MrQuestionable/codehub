class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for(int i = 0; i <= n; i++){
            dp[i] = i - 1; 
        }
        
        for(int i = 0; i < n; i++){
            
            for(int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; l--, r++){
                dp[r + 1] = min(dp[r + 1], dp[l] + 1);
            }
            for(int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++){
                dp[r + 1] = min(dp[r + 1], dp[l] + 1);
            }
        }
        return dp[n];
    }
};