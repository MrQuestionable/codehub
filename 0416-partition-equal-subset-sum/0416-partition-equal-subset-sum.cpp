class Solution {
public:
    bool solve(int ind,int target,vector<int>& nums,vector<vector<int>> &dp){
        int n=nums.size();
        if(target==0)return true;
        if(ind==0)return nums[0]==target;
        if(dp[ind][target]!=-1)return dp[ind][target];
        bool notake=solve(ind-1,target,nums,dp);
        bool take=false;
        if(target>=nums[ind])take=solve(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target]=take|notake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        
        int totsum=0;
        for(int i=0;i<n;i++)totsum+=nums[i];
        if(totsum%2!=0)return false;
        int target=totsum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,nums,dp);
    }
};