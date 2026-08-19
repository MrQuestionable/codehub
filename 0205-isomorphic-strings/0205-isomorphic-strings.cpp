class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())return false;
        int maps[256]={0};
        int mapt[256]={0};
        for(int i=0; i<s.size();i++){
           if(maps[s[i]]!=mapt[t[i]])return false;
            maps[s[i]]=i+1;
            mapt[t[i]]=i+1;
        }
        return true;
    }
};