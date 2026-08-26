class Solution {
public:
    void solve(int ind,string s,string digits,vector<string> &ans){
        string map [10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(ind==digits.size()){
            ans.push_back(s);
            return;
        }
        int num=digits[ind]-'0';
        string va=map[num];
        for(int i=0;i<va.size();i++){
            s.push_back(va[i]);
            solve(ind+1,s,digits,ans);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0)return ans;
        string s;
        solve(0,s,digits,ans);
        return ans;
    }
};