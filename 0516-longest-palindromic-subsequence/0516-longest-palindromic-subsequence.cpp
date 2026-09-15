class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size(),m=t.size();
        vector<int> prev(m + 1, 0);
        for(int i=1;i<=n;i++){
            int dia=prev[0];
            for(int j=1;j<=m;j++){
                int temp=prev[j];
                if(s[i-1]==t[j-1])prev[j]=1+dia;
                else prev[j]=max(prev[j],prev[j-1]);
                dia=temp;
            }
        }
    return prev[m];   
    }
};