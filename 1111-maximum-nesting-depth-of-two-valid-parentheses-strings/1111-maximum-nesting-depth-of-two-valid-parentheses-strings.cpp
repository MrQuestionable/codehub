class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.length());
        int depth=0;
        for(int i=0;i<seq.size();i++){
            if(seq[i]=='('){
                depth++;
                ans[i]=depth%2==0?1:0;
            }
            else{
                ans[i]=depth%2==0?1:0;
                depth--;
            }  
        }
    return ans;      
    }
};