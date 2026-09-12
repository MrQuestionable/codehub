class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totsum = 0;
        
        for(int i = 0; i < n; i++) totsum += nums[i];
        
        if(totsum % 2 != 0) return false;
        int target = totsum / 2;
        
        vector<bool> prev(target + 1, false);
        prev[0] = true;
        if(nums[0] <= target) prev[nums[0]] = true;
        for(int i = 1; i < n; i++){
            for(int t = target; t >= 1; t--){
                
                bool notake = prev[t];
                
                bool take = false;
                if(t >= nums[i]) take = prev[t - nums[i]];
                prev[t] = take | notake;
            }
        }
        
        return prev[target];    
    }
};