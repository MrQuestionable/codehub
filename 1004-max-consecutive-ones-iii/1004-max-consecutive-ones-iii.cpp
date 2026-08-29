class Solution {
public:
    int longestOnes(vector<int>&a, int k) {
        int l = 0;int n = a.size();
        int ans = 0;
        int zero = 0;
        for(int r = 0;r<n;r++){
            if(a[r]==0){
                zero++;
                while(zero>k){
                    if(a[l]==0){
                        zero--;
                    }
                    l++;
                }
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};