class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());
        vector<int> prev(n+1,0);
        for(int i=1;i<=n;i++){
            int dia=prev[0];
            for(int j=1;j<=n;j++){
                int temp=prev[j];
                if(s[i-1]==t[j-1])prev[j]=1+dia;
                else prev[j]=max(prev[j],prev[j-1]);
                dia=temp;
            }
        }
    return n-prev[n];    
    }
};