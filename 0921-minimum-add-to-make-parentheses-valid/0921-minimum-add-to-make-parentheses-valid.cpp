class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnto=0,cntc=0;
        for (char c : s) {
            if (c == '(') {
                cntc++;
            } else if (c == ')') {
                if (cntc > 0) {
                    cntc--;
                } else {
                    cnto++;
                }
            }
        }
    return cntc+cnto;    
    }
};