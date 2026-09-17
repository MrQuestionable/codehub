class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<int> prev(m+1,0);
        for(int j=0;j<=m;j++)prev[j]=j;

        for(int i=1;i<=n;i++){
            int dia=prev[0];
            prev[0]=i;
            for(int j=1;j<=m;j++){
                int temp=prev[j];
                if(word1[i-1]==word2[j-1])prev[j]=dia;
                else prev[j]=1+min({dia,prev[j],prev[j-1]});
                dia=temp;
            }
        }
    return prev[m];    
    }
};