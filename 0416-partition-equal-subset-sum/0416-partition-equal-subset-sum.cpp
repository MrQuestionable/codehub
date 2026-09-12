class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totsum = 0;
        for(int i = 0; i < n; i++) totsum += nums[i];
        
        if(totsum % 2 != 0) return false;
        int target = totsum / 2;
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        if(nums[0] <= target) dp[0][nums[0]] = true;
        for(int i = 1; i < n; i++){
            for(int t = 1; t <= target; t++){
                
                bool notake = dp[i-1][t];
                
                bool take = false;
                if(t >= nums[i]) take = dp[i-1][t - nums[i]];
                dp[i][t] = take | notake;
            }
        }
        return dp[n-1][target];    
    }
};