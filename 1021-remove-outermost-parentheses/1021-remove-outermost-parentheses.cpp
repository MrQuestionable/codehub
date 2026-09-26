class Solution {
public:
    string removeOuterParentheses(string s) {
        string st="";
        int cnt=0;
        for(char c:s){
            if(c==')')cnt--;
            if(cnt!=0)st.push_back(c);
            if(c=='(')cnt++;
        }
    return st;    
    }
};