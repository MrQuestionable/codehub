class Solution {
public:
    void backtrack(int i, string& s, int left_rem, int right_rem, int balance, string& curr, unordered_set<string>& res) {
        if (balance < 0) return;
        
        if (i == s.length()) {
            if (left_rem == 0 && right_rem == 0 && balance == 0) {
                res.insert(curr);
            }
            return;
        }
        
        char c = s[i];
        
        if (c == '(' && left_rem > 0) {
            backtrack(i + 1, s, left_rem - 1, right_rem, balance, curr, res);
        }
        if (c == ')' && right_rem > 0) {
            backtrack(i + 1, s, left_rem, right_rem - 1, balance, curr, res);
        }
        
        curr.push_back(c);
        
        if (c == '(') {
            backtrack(i + 1, s, left_rem, right_rem, balance + 1, curr, res);
        } else if (c == ')') {
            backtrack(i + 1, s, left_rem, right_rem, balance - 1, curr, res);
        } else {
            backtrack(i + 1, s, left_rem, right_rem, balance, curr, res);
        }
        
        curr.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        int left_rem = 0, right_rem = 0;
        for (char c : s) {
            if (c == '(') {
                left_rem++;
            } else if (c == ')') {
                if (left_rem > 0) left_rem--;
                else right_rem++;
            }
        }
        
        unordered_set<string> res_set;
        string curr = "";
        backtrack(0, s, left_rem, right_rem, 0, curr, res_set);
    
        return vector<string>(res_set.begin(), res_set.end());
    }
};