class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxel=nums[0],n=nums.size();
        vector<int> prefix(nums.size());
        prefix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;--i){
            prefix[i]=min(prefix[i+1],nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            maxel=max(maxel,nums[i]);
            if(maxel-prefix[i]<=k)return i;
        }
    return -1;    
    }
};