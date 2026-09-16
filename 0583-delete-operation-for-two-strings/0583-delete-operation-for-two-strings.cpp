class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<int> prev(m+1,0);
        for(int i=1;i<=n;i++){
            int dia=prev[0];
            for(int j =1;j<=m;j++){
                int temp=prev[j];
                if(word1[i-1]==word2[j-1])prev[j]=1+dia;
                else prev[j]=max(prev[j],prev[j-1]);
                dia=temp;
            }
        }
    return n+m -2*prev[m];    
    }
};