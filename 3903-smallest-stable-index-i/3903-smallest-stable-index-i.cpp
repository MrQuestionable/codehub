class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size(),curr_max=nums[0];
        if(n==0)return -1;
        vector<int> suffix_min(n);
        suffix_min[n-1]=nums[n-1];
        for(int i=n-2;i>=0;--i){
            suffix_min[i]=min(suffix_min[i+1],nums[i]);
        }
        for(int i=0;i<n;++i){
            curr_max=max(curr_max,nums[i]);
            if(curr_max-suffix_min[i]<=k)return i;
        }
    return -1;    
    }
};