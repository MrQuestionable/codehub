class Solution {
private:
    int solve(string& s, string& t, int i, int j, vector<vector<int>>& memo) {
        if (j == t.length()) return 1;
        if (i == s.length()) return 0; 
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (s[i] == t[j])memo[i][j] = solve(s, t, i + 1, j + 1, memo) + solve(s, t, i + 1, j, memo);
         else memo[i][j] = solve(s, t, i + 1, j, memo);
        return memo[i][j];
    }

public:
    int numDistinct(string s, string t) {
        vector<vector<int>> memo(s.length(), vector<int>(t.length(), -1));
        return solve(s, t, 0, 0, memo);
    }
};