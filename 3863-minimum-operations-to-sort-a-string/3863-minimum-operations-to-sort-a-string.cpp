class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        bool is_sorted = true;
        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) {
                is_sorted = false;
                break;
            }
        }
        if (is_sorted) return 0;
        
        if (n == 2) return -1;
        
        char min_char = s[0], max_char = s[0];
        for (char c : s) {
            if (c < min_char) min_char = c;
            if (c > max_char) max_char = c;
        }
        
        if (s[0] == min_char || s[n - 1] == max_char) {
            return 1;
        }
        
        int min_count = 0, max_count = 0;
        for (char c : s) {
            if (c == min_char) min_count++;
            if (c == max_char) max_count++;
        }
        
        if (s[0] == max_char && s[n - 1] == min_char && min_count == 1 && max_count == 1) {
            return 3;
        }
        
        return 2;
    }
};