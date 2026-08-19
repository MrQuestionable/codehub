class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i=0,count=0;
        for(int j=0; j<t.size();j++){
            if(s[i]==t[j]){
                count++,i++;
            }
        }
        if(count==s.size())return true;
        else return false;
    
    }
};