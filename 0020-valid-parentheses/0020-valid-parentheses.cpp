#include<bits/stdc++.h>
class Solution {
public:
    bool check(char c,stack<char> &st){
        if(c==')'&&st.top()=='(')return true;
        if(c==']'&&st.top()=='[')return true;
        if(c=='}'&&st.top()=='{')return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='('||c=='{'||c=='['){
                st.push(c);
            }
            else if(c==')'||c=='}'||c==']'){
                if(st.empty())return false;
                if(check(c,st)){
                    st.pop();
                }
                else return false;
            }
        } 
    return st.empty();    
    }
};