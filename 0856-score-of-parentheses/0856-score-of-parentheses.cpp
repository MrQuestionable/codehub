class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int depth = 0;
        int sum = 0;
        int mx = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(') {
                depth += 1;
            } else {
                depth -= 1;
                if (s[i - 1] == '(') {
                    ans += 1 << (depth);
                }
            }
        }
        return ans;
    }
};