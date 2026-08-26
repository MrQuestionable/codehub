class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> ans = {""};
        for(int i=0;i<digits.length();i++){
            string let = mp[digits[i]-'0'];
            vector<string> temp;
            for(string s:ans){
                for(int j=0;j<let.length();j++){
                    temp.push_back(s+let[j]);
                }
            }
            ans = temp;
        }
        return ans;
    }
};