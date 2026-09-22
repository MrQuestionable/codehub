class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(),lasta=-1,lastb=-1,lastc=-1,cnt=0;
            for(int i=0;i<n;i++){
            if(s[i]=='a')lasta=i;
            else if(s[i]=='b')lastb=i;
            else if(s[i]=='c')lastc=i;
            if(lasta!=-1 && lastb!=-1 && lastc!=-1){
                int mini=min({lasta,lastb,lastc});
                cnt+=mini+1;
            }
        }
    return cnt;    
    }
};