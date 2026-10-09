class Solution {
public:
    int minInsertions(string s) {
        int cnto=0,cntc=0;
        for(char c:s){
            if(c=='('){
                if(cntc%2!=0){
                    cnto++;
                    cntc--;
                }
                cntc+=2;
            }
            else if(c==')'){
                cntc--;
                if(cntc<0){
                    cnto++;
                    cntc+=2;
                }
                
            }
        }
    return cnto+cntc;    
    }
};